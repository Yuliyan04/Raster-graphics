#include "ImagePBM.h"


ImagePBM::ImagePBM(unsigned width, unsigned height, const String& magicNumber, const String& fileName, const BitSet& data)
    : Image(width, height, 1, fileName, magicNumber), imageData(data) {}

ImagePBM::ImagePBM(unsigned width, unsigned height, const String& magicNumber, const String& fileName, BitSet&& data)
    : Image(width, height, 1, fileName, magicNumber), imageData(std::move(data)) {}



// PBM images are monochrome by default
void ImagePBM::grayscale() 
{
}

// PBM images are monochrome by default
void ImagePBM::monochrome() 
{
}

void ImagePBM::negative()
{
    for (unsigned i = 0; i < width * height; i++) 
    {
        if (imageData.contains(i))
        {
            imageData.remove(i);
        }
        else 
        {
            imageData.add(i);
        }
    }
}


Image* ImagePBM::clone() const
{
    return new ImagePBM(*this);
}

void ImagePBM::rotateLeft() 
{
    BitSet rotatedData(height * width);

    for (unsigned i = 0; i < height; i++)
    {
        for (unsigned j = 0; j < width; j++)
        {
            if (imageData.contains(i * width + j)) 
            {
                rotatedData.add((width - 1 - j) * height + i);
            }
        }
    }

    std::swap(width, height);
    imageData = std::move(rotatedData);
}

void ImagePBM::rotateRight() 
{
    BitSet rotatedData(height * width);

    for (unsigned i = 0; i < height; i++)
    {
        for (unsigned j = 0; j < width; j++) 
        {
            if (imageData.contains(i * width + j))
            {
                rotatedData.add(j * height + (height - 1 - i));
            }
        }
    }

    std::swap(width, height);
    imageData = std::move(rotatedData);
}