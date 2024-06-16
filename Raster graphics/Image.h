#pragma once
#include <fstream>
#include "String.h"

class Image
{
protected:
	unsigned width = 0;
	unsigned hight = 0;
	uint16_t maxColorNumber = 0;
	String imageName;
	String magicNumber;
	String direction;

public:
    Image(unsigned width, unsigned height, uint16_t maxColorNumber, const String& imageName, const String& magicNumber, const String& direction);
    virtual ~Image() = default;

    virtual void grayscale() = 0;
    virtual void monochrome() = 0;
    virtual void negative() = 0;

    virtual Image* clone() const = 0;

    virtual void readFromFile(std::ifstream& file) = 0;
    virtual void writeToFile(std::ofstream& file) const = 0;

    virtual void rotate(const String& direction) = 0;

    unsigned getWidth() const;
    unsigned getHeight() const;
    uint16_t getMaxColorNumber() const;
    const String& getImageName() const;
    const String& getMagicNumber() const;
    const String& getDirection() const;

    void setWidth(unsigned width);
    void setHeight(unsigned height);
    void setMaxColorNumber(uint16_t maxColorNumber);
    void setImageName(const String& imageName);
    void setMagicNumber(const String& magicNumber);
    void setDirection(const String& direction);
};

