#pragma once
#include "Image.h"
#include "BitSet.h"

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
    void rotate(const String& direction) override;

    void save() const override;

    virtual Image* clone() const override;
};

