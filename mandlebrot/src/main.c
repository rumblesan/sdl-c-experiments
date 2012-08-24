#include "mandelbrot.h"


int main(int argc, char* argv[])
{
    Mandelbrot brot = brot_create(1024, 768, 10, 5.0, 5.0, -5.0, -5.0);

    brot_cleanup(brot);

    return 0;
}

