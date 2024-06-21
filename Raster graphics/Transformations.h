#pragma once
#include "Pixel.h"

class Transformations
{
public:
    static void grayscale(Pixel** pixels, unsigned width, unsigned height);
    static void monochrome(Pixel** pixels, unsigned width, unsigned height);
    static void negative(Pixel** pixels, unsigned width, unsigned height);
    static void rotateLeft(Pixel**& pixels, unsigned& width, unsigned& height);
    static void rotateRight(Pixel**& pixels, unsigned& width, unsigned& height);
};

