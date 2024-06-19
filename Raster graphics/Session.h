#pragma once
#include "ImageCollection.h"
#include "ImageFactory.h"
#include "ImageUtilities.h"
#include "String.h"
#include "Vector.hpp"
#include <sstream>



class Session
{
public:
    static int sIdCounter;

    Session();
    Session(const Session& other);
    Session(Session&& other) noexcept;
    Session& operator=(const Session& other);
    Session& operator=(Session&& other) noexcept;
    ~Session();

    int getId() const;

    void addImage(Image* image);

    void rotate(const String& direction);

    void grayscale();
    void monochrome();
    void negative();

    void saveChanges();
    void saveAs(const String& fileName);

    void undo();

    void close();

    String info() const;

    bool containsFile(const String& fileLocation) const;

    bool areThereUnsavedChanges() const;

private:
    int nId;
    ImageCollection images;
    Vector<String> unsavedTransformations;

    void saveImageToFile(Image* image, const String& fileName);

    void copyFrom(const Session& other);
    void moveFrom(Session&& other);
    void free();

};

