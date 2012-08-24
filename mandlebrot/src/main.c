#include <stdio.h>
#include <SDL/SDL.h>

#include "mandelbrot.h"

#define WIDTH  2560
#define HEIGHT 1440
#define BPP    4
#define DEPTH  32

void setpixel(SDL_Surface *screen, int x, int y, Uint8 r, Uint8 g, Uint8 b)
{
    int xPos, yPos;

    xPos = x;
    // Moving this into the setpixel method to simplify
    // Should be moved back out to optimise if necessary
    yPos = (y * screen->pitch) / BPP;

    Uint32 *pixmem32;
    Uint32 colour;

    colour = SDL_MapRGB(screen->format, r, g, b );

    pixmem32 = (Uint32*) screen->pixels + yPos + xPos;
    *pixmem32 = colour;
}

void draw_screen(Mandelbrot brot, SDL_Surface* screen)
{
    int xPos, yPos, colour;

    if(SDL_MUSTLOCK(screen)) {
        if(SDL_LockSurface(screen) < 0) {
            return;
        }
    }

    for (yPos = 0; yPos < screen->h; yPos++) {
        for (xPos = 0; xPos < screen->w; xPos++) {
            colour = brot->pixels[xPos][yPos];
            setpixel(screen, xPos, yPos, colour, colour, colour);
        }
    }

    if(SDL_MUSTLOCK(screen)) {
        SDL_UnlockSurface(screen);
    }

    SDL_Flip(screen);

}

int main(int argc, char* argv[])
{
    SDL_Surface *screen;
    SDL_Event event;

    int keypress = 0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0 ) return 1;

    if (!(screen = SDL_SetVideoMode(WIDTH, HEIGHT, DEPTH, SDL_FULLSCREEN|SDL_HWSURFACE))) {
        SDL_Quit();
        return 1;
    }

    Mandelbrot brot = brot_create(WIDTH, HEIGHT, 255, -2.5, -1.0, 1.0, 1.0);

    brot_calculate(brot);

    draw_screen(brot, screen);

    while(!keypress) {

        while(SDL_PollEvent(&event)) {

            switch (event.type) {

            case SDL_QUIT:
                keypress = 1;
                break;
            case SDL_KEYDOWN:
                keypress = 1;
                break;

            }
        }
    }

    SDL_Quit();

    brot_cleanup(brot);

    return 0;
}

