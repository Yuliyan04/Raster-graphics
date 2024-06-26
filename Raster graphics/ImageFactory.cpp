#include "ImageFactory.h"

Image* ImageFactory::imageFactory(const String& fileName) 
{
    std::ifstream inFile(fileName.c_str(), std::ios::binary);

    if (!inFile.is_open()) 
    {
        std::cout << "Could not open file: " << fileName;
        return nullptr;
    }

    String magicNumber;
    inFile >> magicNumber;

    if (magicNumber == "P1") 
    {
        return readPBM(fileName);
    }
    else if (magicNumber == "P2") 
    {
        return readPGM(fileName);
    }
    else if (magicNumber == "P3") 
    {
        return readPPM(fileName);
    }
    else
    {
        std::cout << "Unsupported file format: " << magicNumber;
        return nullptr;
    }

    inFile.close();
}

Image* ImageFactory::readPBM(const String& fileName) 
{
    std::ifstream inFile(fileName.c_str(), std::ios::binary);
    if (!inFile.is_open()) 
    {
        std::cout << "Could not open file: " << fileName;
        return nullptr;
    }

    String magicNumber;
    unsigned width, height;

    inFile >> magicNumber >> width >> height;

    BitSet data(width * height);

    for (unsigned i = 0; i < height; i++)
    {
        for (unsigned j = 0; j < width; j++)
        {
            int value;
            inFile >> value;

            if (value == 1)
            {
                data.add(i * width + j);
            }
        }
    }
    inFile.close();

    return new ImagePBM(width, height, magicNumber, fileName, std::move(data));
}

Image* ImageFactory::readPGM(const String& fileName)
{
    std::ifstream inFile(fileName.c_str(), std::ios::binary);

    if (!inFile.is_open())
    {
        std::cout << "Could not open file: " << fileName;
        return nullptr;
    }

    String magicNumber;
    unsigned width, height, maxColorNumber;

    inFile >> magicNumber >> width >> height >> maxColorNumber;

    uint8_t** pixels = new uint8_t * [height];

    for (unsigned i = 0; i < height; i++)
    {
        pixels[i] = new uint8_t[width];

        for (unsigned j = 0; j < width; j++)
        {
            int num;
            inFile >> num;
            pixels[i][j] = (uint8_t)num;
        }
    }
    inFile.close();

    return new ImagePGM(width, height, maxColorNumber, magicNumber, fileName, pixels);
}

Image* ImageFactory::readPPM(const String& fileName)
{
    std::ifstream inFile(fileName.c_str(), std::ios::binary);

    if (!inFile.is_open())
    {
        std::cout << "Could not open file: " << fileName;
        return nullptr;
    }

    String magicNumber;
    unsigned width, height, maxColorNumber;

    inFile >> magicNumber >> width >> height >> maxColorNumber;

    Pixel** pixels = new Pixel * [height];

    for (unsigned i = 0; i < height; i++)
    {
        pixels[i] = new Pixel[width];

        for (unsigned j = 0; j < width; j++)
        {
            int r, g, b;
            inFile >> r >> g >> b;
            pixels[i][j] = Pixel((unsigned char)r, (unsigned char)g, (unsigned char)b);
        }
    }
    inFile.close();

    return new ImagePPM(width, height, maxColorNumber, magicNumber, fileName, pixels);
}

void ImageFactory::writePBM(const ImagePBM* image, const String& fileName) 
{
    std::ofstream file(fileName.c_str());
    if (!file.is_open()) 
    {
        throw std::runtime_error("Failed to open file for writing");
    }

    image->writeASCII(file);
    file.close();
}

void ImageFactory::writePGM(const ImagePGM* image, const String& fileName) 
{
    std::ofstream file(fileName.c_str());
    if (!file.is_open()) 
    {
        throw std::runtime_error("Failed to open file for writing");
    }

    image->writeASCII(file);
    file.close();
}

void ImageFactory::writePPM(const ImagePPM* image, const String& fileName) 
{
    std::ofstream file(fileName.c_str());
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file for writing");
    }

    image->writeASCII(file);
    file.close();
}

void ImageFactory::writeImage(const Image* image, const String& fileName) 
{
    const ImagePBM* pbmImage = (const ImagePBM*)image;
    if (pbmImage) 
    {
        writePBM(pbmImage, fileName);
        return;
    }

  
    const ImagePGM* pgmImage = (const ImagePGM*)image;
    if (pgmImage) 
    {
        writePGM(pgmImage, fileName);
        return;
    }

    const ImagePPM* ppmImage = (const ImagePPM*)image;
    if (ppmImage) 
    {
        writePPM(ppmImage, fileName);
        return;
    }

    throw std::runtime_error("Unsupported image type");
}

