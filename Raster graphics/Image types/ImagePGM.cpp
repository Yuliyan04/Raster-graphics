#include "ImagePGM.h"


ImagePGM::ImagePGM(unsigned width, unsigned height, unsigned maxColorNumber, const String& magicNumber, const String& fileName, const uint8_t* const* pixels)
    : Image(width, height, maxColorNumber, fileName, magicNumber)
{
    this->pixels = new uint8_t * [height];

    for (unsigned i = 0; i < height; i++)
    {
        this->pixels[i] = new uint8_t[width];

        for (unsigned j = 0; j < width; j++)
        {
            this->pixels[i][j] = pixels[i][j];
        }
    }
}

ImagePGM::ImagePGM(unsigned width, unsigned height, unsigned maxColorNumber, const String& magicNumber, const String& fileName, uint8_t**&& pixels)
    : Image(width, height, maxColorNumber, fileName, magicNumber), pixels(pixels) 
{
    pixels = nullptr;
}

ImagePGM::ImagePGM(const ImagePGM& other)
    : Image(other.width, other.height, other.maxColorNumber, other.imageName, other.magicNumber)
{
    copyFrom(other);
}

ImagePGM::ImagePGM(ImagePGM&& other) noexcept
    : Image(other.width, other.height, other.maxColorNumber, std::move(other.imageName), std::move(other.magicNumber)) 
{
    moveFrom(std::move(other));
}

ImagePGM& ImagePGM::operator=(const ImagePGM& other) 
{
    if (this != &other) 
    {
        free();
        Image::width = other.width;
        Image::height = other.height;
        Image::maxColorNumber = other.maxColorNumber;
        Image::imageName = other.imageName;
        Image::magicNumber = other.magicNumber;
        copyFrom(other);
    }
    return *this;
}

ImagePGM& ImagePGM::operator=(ImagePGM&& other) noexcept 
{
    if (this != &other)
    {
        free();
        Image::width = other.width;
        Image::height = other.height;
        Image::maxColorNumber = other.maxColorNumber;
        Image::imageName = std::move(other.imageName);
        Image::magicNumber = std::move(other.magicNumber);
        moveFrom(std::move(other));
    }
    return *this;
}

ImagePGM::~ImagePGM()
{
    free();
}

// PGM images are grayscaled by default
void ImagePGM::grayscale() 
{
}

void ImagePGM::monochrome() 
{
    for (unsigned i = 0; i < height; i++) 
    {
        for (unsigned j = 0; j < width; j++) 
        {
            pixels[i][j] = (pixels[i][j] > 127) ? 255 : 0;
        }
    }
}

void ImagePGM::negative()
{
    for (unsigned i = 0; i < height; i++) 
    {
        for (unsigned j = 0; j < width; j++)
        {
            pixels[i][j] = maxColorNumber - pixels[i][j];
        }
    }
}


Image* ImagePGM::clone() const
{
    return new ImagePGM(*this);
}

void ImagePGM::free()
{
    if (pixels) 
    {
        for (unsigned i = 0; i < height; i++) 
        {
            delete[] pixels[i];
        }
        delete[] pixels;
        pixels = nullptr;
    }
}

void ImagePGM::copyFrom(const ImagePGM& other) 
{
    free();

    pixels = new uint8_t * [other.height];

    for (unsigned i = 0; i < other.height; i++)
    {
        pixels[i] = new uint8_t[other.width];

        for (unsigned j = 0; j < other.width; j++)
        {
            pixels[i][j] = other.pixels[i][j];
        }
    }

    width = other.width;
    height = other.height;
    maxColorNumber = other.maxColorNumber;
    magicNumber = other.magicNumber;
}

void ImagePGM::moveFrom(ImagePGM&& other) 
{
    pixels = other.pixels;
    other.pixels = nullptr;
}

void ImagePGM::rotateLeft() 
{
    uint8_t** newPixels = new uint8_t * [width];

    for (unsigned i = 0; i < width; i++)
    {
        newPixels[i] = new uint8_t[height];
    }

    for (unsigned i = 0; i < height; i++) 
    {
        for (unsigned j = 0; j < width; j++) 
        {
            newPixels[width - 1 - j][i] = pixels[i][j];
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

void ImagePGM::rotateRight() 
{
    uint8_t** newPixels = new uint8_t * [width];

    for (unsigned i = 0; i < width; i++) 
    {
        newPixels[i] = new uint8_t[height];
    }

    for (unsigned i = 0; i < height; i++)
    {
        for (unsigned j = 0; j < width; j++) 
        {
            newPixels[j][height - 1 - i] = pixels[i][j];
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

void ImagePGM::writeASCII(std::ofstream& file) const 
{
    file << magicNumber << "\n";
    file << width << " " << height << "\n";
    file << maxColorNumber << "\n";

    for (unsigned i = 0; i < height; i++) 
    {
        for (unsigned j = 0; j < width; j++) 
        {
            file << (int)pixels[i][j] << " ";  
        }
        file << "\n";
    }
}