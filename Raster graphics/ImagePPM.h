#pragma once
#include "Image.h"
#include "Pixel.h"
#include "ImageUtilities.h"




class ImagePPM : public Image
{
private:
    Pixel** pixels = nullptr; 

public:
    ImagePPM(unsigned width, unsigned height, unsigned maxColorNumber, const String& magicNumber, const String& fileName, const Pixel* const* pixels);
    ImagePPM(unsigned width, unsigned height, unsigned maxColorNumber, const String& magicNumber, const String& fileName, Pixel**&& pixels);
    ImagePPM(const ImagePPM& other);
    ImagePPM(ImagePPM&& other) noexcept;
    ImagePPM& operator=(const ImagePPM& other);
    ImagePPM& operator=(ImagePPM&& other) noexcept;
    ~ImagePPM();


    void grayscale() override;
    void monochrome() override;
    void negative() override;

    void save()const override; //TODO

    void rotateLeft() override;
    void rotateRight() override;

    Image* clone() const override;

private:
    void free();
    void copyFrom(const ImagePPM& other);
    void moveFrom(ImagePPM&& other);
};

