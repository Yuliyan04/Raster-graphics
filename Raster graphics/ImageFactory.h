#pragma once
#include "Image.h"
#include "ImagePBM.h"
#include "ImagePGM.h"
#include "ImagePPM.h"


class ImageFactory
{
public:
    static Image* imageFactory(const String& fileName);
    static void writeImage(const Image* image, const String& fileName);

private:
    static Image* readPBM(const String& fileName);
    static Image* readPGM(const String& fileName);
    static Image* readPPM(const String& fileName);

    static void writePBM(const ImagePBM* image, const String& fileName);
    static void writePGM(const ImagePGM* image, const String& fileName);
    static void writePPM(const ImagePPM* image, const String& fileName);

};

