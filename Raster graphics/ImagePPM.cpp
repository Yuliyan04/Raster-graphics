#include "ImagePPM.h"


void ImagePPM::free()
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

void ImagePPM::copyFrom(const ImagePPM& other)
{
    pixels = new Pixel * [height];
    for (unsigned i = 0; i < height; i++)
    {
        pixels[i] = new Pixel[width];
        std::memcpy(pixels[i], other.pixels[i], width * sizeof(Pixel));
    }
}

void ImagePPM::moveFrom(ImagePPM&& other)
{
    pixels = other.pixels;
    other.pixels = nullptr;
}



ImagePPM::ImagePPM(unsigned width, unsigned height, unsigned maxColorNumber, const String& magicNumber, const String& fileName, const Pixel* const* pixels)
    : Image(width, height, maxColorNumber, fileName, magicNumber)
{
    this->pixels = new Pixel * [height];

    for (unsigned i = 0; i < height; i++)
    {
        this->pixels[i] = new Pixel[width];
        std::memcpy(this->pixels[i], pixels[i], width * sizeof(Pixel));
    }
}

ImagePPM::ImagePPM(unsigned width, unsigned height, unsigned maxColorNumber, const String& magicNumber, const String& fileName, Pixel**&& pixels)
    : Image(width, height, maxColorNumber, fileName, magicNumber), pixels(pixels) 
{
    pixels = nullptr;
}

ImagePPM::ImagePPM(const ImagePPM& other)
    : Image(other.width, other.height, other.maxColorNumber, other.imageName, other.magicNumber) 
{
    copyFrom(other);
}

ImagePPM::ImagePPM(ImagePPM&& other) noexcept
    : Image(other.width, other.height, other.maxColorNumber, std::move(other.imageName), std::move(other.magicNumber)) 
{
    moveFrom(std::move(other));
}

ImagePPM& ImagePPM::operator=(const ImagePPM& other)
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

ImagePPM& ImagePPM::operator=(ImagePPM&& other) noexcept
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

ImagePPM::~ImagePPM() 
{
    free();
}




void ImagePPM::grayscale()
{
    for (unsigned i = 0; i < height; i++) 
    {
        for (unsigned j = 0; j < width; j++) 
        {
            unsigned char grayscaleValue = pixels[i][j].getGrayscale();
            pixels[i][j] = Pixel(grayscaleValue, grayscaleValue, grayscaleValue);
        }
    }
}

void ImagePPM::monochrome()
{
    for (unsigned i = 0; i < height; i++)
    {
        for (unsigned j = 0; j < width; j++) 
        {
            unsigned char grayscaleValue = pixels[i][j].getGrayscale();
            pixels[i][j] = Pixel(grayscaleValue > 127 ? 255 : 0, grayscaleValue > 127 ? 255 : 0, grayscaleValue > 127 ? 255 : 0);
        }
    }
}

void ImagePPM::negative()
{
    for (unsigned i = 0; i < height; i++) 
    {
        for (unsigned j = 0; j < width; j++) 
        {
            pixels[i][j] = Pixel(maxColorNumber - pixels[i][j].getRed(),
                maxColorNumber - pixels[i][j].getGreen(),
                maxColorNumber - pixels[i][j].getBlue());
        }
    }
}


Image* ImagePPM::clone() const 
{
    return new ImagePPM(*this);
}

void ImagePPM::rotateLeft() 
{
    ImageUtilities::rotateLeft(pixels, width, height);
}

void ImagePPM::rotateRight()
{
    ImageUtilities::rotateRight(pixels, width, height);
}
