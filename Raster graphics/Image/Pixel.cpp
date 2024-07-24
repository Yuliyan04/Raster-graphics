#include "Pixel.h"

Pixel::Pixel() : r(0), g(0), b(0) {}

Pixel::Pixel(unsigned char red, unsigned char green, unsigned char blue) : r(red), g(green), b(blue) {}


char Pixel::getGrayscale() const 
{
    return 0.3 * r + 0.59 * g + 0.11 * b;
}

unsigned char Pixel::getRed() const
{
    return r;
}

unsigned char Pixel::getGreen() const 
{
    return g;
}

unsigned char Pixel::getBlue() const 
{
    return b;
}