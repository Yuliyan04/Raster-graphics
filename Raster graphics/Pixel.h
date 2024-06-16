#pragma once
#include <iostream>

class Pixel {
private:
    unsigned char r;
    unsigned char g; 
    unsigned char b;

public:
    Pixel();
    Pixel(unsigned char grayscale);
    Pixel(unsigned char red, unsigned char green, unsigned char blue);

    bool isGray() const;
    unsigned char getGrayscale() const;

    unsigned char getRed() const;
    unsigned char getGreen() const;
    unsigned char getBlue() const;

    void setRed(unsigned char red);
    void setGreen(unsigned char green);
    void setBlue(unsigned char blue);

    bool operator==(const Pixel& other) const;
    bool operator!=(const Pixel& other) const;
};

