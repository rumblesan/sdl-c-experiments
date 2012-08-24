#include <stdlib.h>

#include "mandelbrot.h"

Mandelbrot brot_create(int pixelWidth, int pixelHeight, int repeats, float x1, float y1, float x2, float y2) {

    Mandelbrot brot = (Mandelbrot) malloc(sizeof(Mandelbrot_Data));

    brot->x1 = x1;
    brot->y1 = y1;

    brot->x2 = x2;
    brot->y2 = y2;

    brot->pixelWidth = pixelWidth;
    brot->pixelHeight = pixelHeight;

    brot->pixels = (int**) malloc(sizeof(int*) * brot->pixelWidth);

    // Assign the memory for the 2D array
    // Actually done as an array of pointers to arrays of ints
    int i;
    for (i = 0; i < brot->pixelWidth; i++) {
        brot->pixels[i] = (int*) malloc(sizeof(int*) * brot->pixelHeight);
    }

    return brot;
}

void brot_cleanup(Mandelbrot brot) {

    int i;

    for (i = 0; i < brot->pixelWidth; i++) {
        free(brot->pixels[i]);
    }

    free(brot->pixels);

    free(brot);
}


