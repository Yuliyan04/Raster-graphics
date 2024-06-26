#include "Pixel.h"

Pixel::Pixel() : r(0), g(0), b(0) {}

Pixel::Pixel(char grayscale) : r(grayscale), g(grayscale), b(grayscale) {}

Pixel::Pixel(unsigned char red, unsigned char green, unsigned char blue) : r(red), g(green), b(blue) {}

bool Pixel::isGray() const
{
    return r == g && g == b;
}

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

void Pixel::setRed(unsigned char red) 
{
    r = red;
}

void Pixel::setGreen(unsigned char green) 
{
    g = green;
}

void Pixel::setBlue(unsigned char blue) 
{
    b = blue;
}

bool Pixel::operator==(const Pixel& other) const 
{
    return r == other.r && g == other.g && b == other.b;
}

bool Pixel::operator!=(const Pixel& other) const 
{
    return !(*this == other);
}