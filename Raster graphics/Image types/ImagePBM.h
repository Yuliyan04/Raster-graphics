#pragma once
#include "Image.h"
#include "BitSet.h"
#include "ImageUtilities.h"

class ImagePBM : public Image
{
private:
	BitSet imageData;

public:
    ImagePBM(unsigned width, unsigned height, const String& magicNumber, const String& fileName, const BitSet& data);
    ImagePBM(unsigned width, unsigned height, const String& magicNumber, const String& fileName, BitSet&& data);


    void grayscale() override;
    void monochrome() override;
    void negative() override;

    void rotateLeft() override;
    void rotateRight() override;
    
    void writeASCII(std::ofstream& file) const override;



    virtual Image* clone() const override;
};

