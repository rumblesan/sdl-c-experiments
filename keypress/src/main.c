#include <stdio.h>
#include <SDL/SDL.h>

#define WIDTH  2560
#define HEIGHT 1440
#define BPP    4
#define DEPTH  32

int main(int argc, char* argv[])
{

    // Create a screen but we won't be drawing to it
    SDL_Surface *screen;
    SDL_Event event;

    int running = 1;

    if (SDL_Init(SDL_INIT_VIDEO) < 0 ) return 1;

    if (!(screen = SDL_SetVideoMode(WIDTH, HEIGHT, DEPTH, SDL_FULLSCREEN|SDL_HWSURFACE))) {
        SDL_Quit();
        return 1;
    }

    char *key;

    while(running) {

        while(SDL_PollEvent(&event)) {

            switch (event.type) {

            case SDL_QUIT:
                running = 0;
                break;
            case SDL_KEYDOWN:
                key = SDL_GetKeyName(event.key.keysym.sym);
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    running = 0;
                } else {
                    printf("The %s key was pressed!\n", key );
                }
                break;


            case SDL_MOUSEBUTTONDOWN:           //mouse button down
                printf("Mouse down x:%d, y:%d\n", event.button.x, event.button.y );
                break; 
            case SDL_MOUSEBUTTONUP:           //mouse button up
                printf("Mouse up x:%d, y:%d\n", event.button.x, event.button.y );
                break; 

            }
        }
    }




    SDL_Quit();

    return 0;
}

