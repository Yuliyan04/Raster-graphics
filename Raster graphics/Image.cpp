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

void Image::setWidth(unsigned _width)
{
    width = _width;
}

void Image::setHeight(unsigned _height) 
{
    height = _height;
}

void Image::setMaxColorNumber(uint16_t _maxColorNumber)
{
    maxColorNumber = _maxColorNumber;
}

void Image::setImageName(const String& _imageName) 
{
    imageName = _imageName;
}

void Image::setMagicNumber(const String& _magicNumber) 
{
    magicNumber = _magicNumber;
}