#pragma once
#include <iostream>

class Pixel {
private:
    unsigned char r;
    unsigned char g; 
    unsigned char b;

public:
    Pixel();
    Pixel(char grayscale);
    Pixel(unsigned char red, unsigned char green, unsigned char blue);

    char getGrayscale() const;
    unsigned char getRed() const;
    unsigned char getGreen() const;
    unsigned char getBlue() const;
};

