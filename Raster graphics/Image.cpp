#include "Image.h"

Image::Image(unsigned width, unsigned height, uint16_t maxColorNumber, const String& imageName, const String& magicNumber)
    : width(width), 
    height(height), 
    maxColorNumber(maxColorNumber), 
    imageName(imageName), 
    magicNumber(magicNumber){}

unsigned Image::getWidth() const 
{
    return width;
}

unsigned Image::getHeight() const 
{
    return height;
}

uint16_t Image::getMaxColorNumber() const 
{
    return maxColorNumber;
}

const String& Image::getImageName() const 
{
    return imageName;
}

const String& Image::getMagicNumber() const
{
    return magicNumber;
}