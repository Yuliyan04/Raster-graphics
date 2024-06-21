#include "Transformations.h"

void Transformations::grayscale(Pixel** pixels, unsigned width, unsigned height)
{
    for (unsigned i = 0; i < height; i++) 
    {
        for (unsigned j = 0; j < width; j++)
        {
            if (!pixels[i][j].isGray()) 
            {
                unsigned char gray = pixels[i][j].getGrayscale();
                pixels[i][j] = Pixel(gray, gray, gray);
            }
        }
    }
}

void Transformations::monochrome(Pixel** pixels, unsigned width, unsigned height) 
{
    for (unsigned i = 0; i < height; i++)
    {
        for (unsigned j = 0; j < width; j++)
        {
            unsigned char gray = pixels[i][j].getGrayscale();
            pixels[i][j] = Pixel(gray > 127 ? 255 : 0, gray > 127 ? 255 : 0, gray > 127 ? 255 : 0);
        }
    }
}

void Transformations::negative(Pixel** pixels, unsigned width, unsigned height)
{
    for (unsigned i = 0; i < height; i++)
    {
        for (unsigned j = 0; j < width; j++)
        {
            pixels[i][j] = Pixel(255 - pixels[i][j].getRed(), 255 - pixels[i][j].getGreen(), 255 - pixels[i][j].getBlue());
        }
    }
}

void Transformations::rotateLeft(Pixel**& pixels, unsigned& width, unsigned& height)
{
    Pixel** newPixels = new Pixel * [width];

    for (unsigned i = 0; i < width; i++) 
    {
        newPixels[i] = new Pixel[height];
    }

    for (unsigned i = 0; i < height; i++)
    {
        for (unsigned j = 0; j < width; j++) 
        {
            newPixels[width - j - 1][i] = pixels[i][j];
        }
    }

    for (unsigned i = 0; i < height; i++) 
    {
        delete[] pixels[i];
    }
    delete[] pixels;

    pixels = newPixels;
    std::swap(width, height);
}

void Transformations::rotateRight(Pixel**& pixels, unsigned& width, unsigned& height) 
{
    Pixel** newPixels = new Pixel * [width];

    for (unsigned i = 0; i < width; i++) 
    {
        newPixels[i] = new Pixel[height];
    }

    for (unsigned i = 0; i < height; i++) 
    {
        for (unsigned j = 0; j < width; j++)
        {
            newPixels[j][height - i - 1] = pixels[i][j];
        }
    }

    for (unsigned i = 0; i < height; i++) 
    {
        delete[] pixels[i];
    }
    delete[] pixels;

    pixels = newPixels;
    std::swap(width, height);
}
