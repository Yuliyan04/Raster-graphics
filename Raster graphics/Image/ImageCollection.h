#pragma once
#include "Image.h"
	
class ImageCollection
{
private:
    Image** data;
    size_t capacity;
    size_t size;

public:
    ImageCollection();
    ImageCollection(const ImageCollection& other);
    ImageCollection(ImageCollection&& other) noexcept;
    ImageCollection& operator=(const ImageCollection& other);
    ImageCollection& operator=(ImageCollection&& other) noexcept;
    ~ImageCollection();

    void addImage(Image* newImage);

    size_t getSize() const;
    Image* getImage(size_t index) const;

private:
    void resize(size_t newCap);
    void free();
    void copyFrom(const ImageCollection& other);
    void moveFrom(ImageCollection&& other);
};