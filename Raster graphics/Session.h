#pragma once
#include "ImageCollection.h"
#include "ImageFactory.h"
#include "ImageUtilities.h"
#include "String.h"
#include "Vector.hpp"
#include <sstream>



class Session
{   
private:
    int sessionID;
    ImageCollection images;
    Vector<String> unsavedTransformations;
    static int counterID;

public:
    Session();
    Session(const Session& other);
    Session(Session&& other) noexcept;
    Session& operator=(const Session& other);
    Session& operator=(Session&& other) noexcept;
    ~Session();

    void addImage(Image* image);

    void rotate(const String& direction);
    void grayscale();
    void monochrome();
    void negative();

    void undo();
    void close();
    String info() const; //TODO

    bool containsFile(const String& fileLocation) const;
    bool hasUnsavedChanges() const;
    int getID() const;

private:
    void free();
    void copyFrom(const Session& other);
    void moveFrom(Session&& other);
};

