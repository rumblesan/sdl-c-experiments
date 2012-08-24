#include <stdlib.h>

#include "mandelbrot.h"

Mandelbrot brot_create(int pixWidth, int pixHeight, int repeats, float x1, float y1, float x2, float y2) {

    Mandelbrot brot = (Mandelbrot) malloc(sizeof(Mandelbrot_Data));

    return brot;
}

void brot_cleanup(Mandelbrot brot) {

    free(brot);
}


