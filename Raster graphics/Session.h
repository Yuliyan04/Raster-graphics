#pragma once
#include "ImageCollection.h"
#include "String.h"
#include "Vector.hpp"


class Session
{
private:
    int sessionId;
    ImageCollection images;
    Vector<String> unsavedChanges;

public:
    static int idCounter;

    Session();
    Session(const Session& other);
    Session(Session&& other) noexcept;
    Session& operator=(const Session& other);
    Session& operator=(Session&& other) noexcept;
    ~Session();

    void grayscale();
    void monochrome();
    void negative();

    void addImage(Image* image);
    void rotate(const String& direction);
    void undo();
    void close();
    String info() const;

    bool containsFile(const String& fileLocation) const;
    bool hasUnsavedChanges() const;

    int getId() const;

private:
    void saveImageToFile(Image* image, const String& fileName);
    void free();
    void copyFrom(const Session& other);
    void moveFrom(Session&& other);
};

