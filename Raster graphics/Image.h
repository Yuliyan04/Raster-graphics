#pragma once
#include <fstream>
#include "String.h"

class Image
{
protected:
    uint16_t maxColorNumber = 0;
	unsigned width = 0;
	unsigned height = 0;
	String imageName;
	String magicNumber;

public:
    Image(unsigned width, unsigned height, uint16_t maxColorNumber, const String& imageName, const String& magicNumber);
    virtual ~Image() = default;

    unsigned getWidth() const;
    unsigned getHeight() const;
    uint16_t getMaxColorNumber() const;
    const String& getImageName() const;
    const String& getMagicNumber() const;

    virtual void grayscale() = 0;
    virtual void monochrome() = 0;
    virtual void negative() = 0;
    virtual void rotate(const String& direction) = 0;

    virtual void save() const = 0;

    virtual Image* clone() const = 0;
};

