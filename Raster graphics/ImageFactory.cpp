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

    if (magicNumber == "P1" || magicNumber == "P4") 
    {
        return readPBM(fileName);
    }
    else if (magicNumber == "P2" || magicNumber == "P5") 
    {
        return readPGM(fileName);
    }
    else if (magicNumber == "P3" || magicNumber == "P6") 
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

    if (magicNumber == "P1") 
    {
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
    }
    else if (magicNumber == "P4") 
    {
        for (unsigned i = 0; i < height; i++)
        {
            for (unsigned j = 0; j < width; j++) 
            {
                unsigned char num;

                inFile.read((char*)&num, sizeof(num));

                if (num) 
                {
                    data.add(i * width + j);
                }
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

        if (magicNumber == "P2") 
        {
            for (unsigned j = 0; j < width; j++)
            {
                int num;
                inFile >> num;
                pixels[i][j] = (uint8_t)num;
            }
        }
        else if (magicNumber == "P5") 
        {
            inFile.read((char*)pixels[i], width * sizeof(uint8_t));
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

        if (magicNumber == "P3")
        {
            for (unsigned j = 0; j < width; j++)
            {
                int r, g, b;
                inFile >> r >> g >> b;
                pixels[i][j] = Pixel((unsigned char)r, (unsigned char)g, (unsigned char)b);
            }
        }
        else if (magicNumber == "P6") 
        {
            inFile.read((char*)pixels[i], width * sizeof(Pixel));
        }
    }

    inFile.close();
    return new ImagePPM(width, height, maxColorNumber, magicNumber, fileName, pixels);
}