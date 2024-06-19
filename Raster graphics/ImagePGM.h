#pragma once
#include "Image.h"
#include "Pixel.h"
#include "ImageUtilities.h"
#include <fstream>


class ImagePGM : public Image
{
private:
    uint8_t** pixels = nullptr;

public:
    ImagePGM(unsigned width, unsigned height, unsigned maxColorNumber, const String& magicNumber, const String& fileName, const uint8_t* const* pixels);
    ImagePGM(unsigned width, unsigned height, unsigned maxColorNumber, const String& magicNumber, const String& fileName, uint8_t**&& pixels);
    ImagePGM(const ImagePGM& other);
    ImagePGM(ImagePGM&& other) noexcept;
    ImagePGM& operator=(const ImagePGM& other);
    ImagePGM& operator=(ImagePGM&& other) noexcept;
    ~ImagePGM();


    void grayscale() override;
    void monochrome() override;
    void negative() override;
    
    void save()const override; //TODO
    void writeASCII(std::ofstream& file) const override;

    void rotateLeft() override;
    void rotateRight() override;
  
    Image* clone() const override;

private:
    void free();
    void copyFrom(const ImagePGM& other);
    void moveFrom(ImagePGM&& other);
};


