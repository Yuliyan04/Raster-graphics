#include "ImageCollection.h"



void ImageCollection::free()
{
    for (size_t i = 0; i < size; i++)
    {
        delete data[i];
        data[i] = nullptr;
    }

    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

void ImageCollection::copyFrom(const ImageCollection& other)
{
    data = new Image * [other.capacity];
    
    for (size_t i = 0; i < other.size; i++)
    {
        data[i] = other.data[i]->clone();
    }

    size = other.size;
    capacity = other.capacity;
}

void ImageCollection::moveFrom(ImageCollection&& other)
{
    data = other.data;
    size = other.size;
    capacity = other.capacity;
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}



ImageCollection::ImageCollection() : data(nullptr), size(0), capacity(0) {};

ImageCollection::ImageCollection(const ImageCollection& other)
{
    copyFrom(other);
}

ImageCollection::ImageCollection(ImageCollection&& other) noexcept
{
    moveFrom(std::move(other));
}

ImageCollection& ImageCollection::operator=(const ImageCollection& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

ImageCollection& ImageCollection::operator=(ImageCollection&& other) noexcept 
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

ImageCollection::~ImageCollection()
{
    free();
}



void ImageCollection::resize(size_t newCap)
{
    if (newCap < size)
    {
        throw std::runtime_error("New capacity must be greater than or equal to current size");
    }

    Image** newData = new Image * [newCap];

    for (size_t i = 0; i < size; i++)
    {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    capacity = newCap;
}

void ImageCollection::addImage(Image* image)
{
    if (size == capacity)
    {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = image;
}


size_t ImageCollection::getSize() const 
{
    return size;
}

Image* ImageCollection::getImage(size_t index) const 
{
    if (index >= size) 
    {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}