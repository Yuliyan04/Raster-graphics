#include "ImageUtilities.h"


void ImageUtilities::rotateLeft(Pixel**& pixels, unsigned& width, unsigned& height)
{
    Pixel** rotatedPixels = new Pixel * [width];

    for (unsigned i = 0; i < width; i++) 
    {
        rotatedPixels[i] = new Pixel[height];
    }

    for (unsigned i = 0; i < height; i++) 
    {
        for (unsigned j = 0; j < width; j++)
        {
            rotatedPixels[width - j - 1][i] = pixels[i][j];
        }
    }

    for (unsigned i = 0; i < height; i++)
    {
        delete[] pixels[i];
    }
    delete[] pixels;

    pixels = rotatedPixels;
    std::swap(width, height);
}

void ImageUtilities::rotateRight(Pixel**& pixels, unsigned& width, unsigned& height) 
{
    Pixel** rotatedPixels = new Pixel * [width];

    for (unsigned i = 0; i < width; i++)
    {
        rotatedPixels[i] = new Pixel[height];
    }

    for (unsigned i = 0; i < height; i++)
    {
        for (unsigned j = 0; j < width; j++)
        {
            rotatedPixels[j][height - i - 1] = pixels[i][j];
        }
    }

    for (unsigned i = 0; i < height; i++)
    {
        delete[] pixels[i];
    }
    delete[] pixels;

    pixels = rotatedPixels;
    std::swap(width, height);
}