#pragma once
#include "Pixel.h"

class ImageUtilities
{
public:
    static void rotateLeft(Pixel**& pixels, unsigned& width, unsigned& height);
    static void rotateRight(Pixel**& pixels, unsigned& width, unsigned& height);
};