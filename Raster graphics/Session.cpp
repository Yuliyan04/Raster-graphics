#include "Session.h"


int Session::counterID = 0;



void Session::free()
{
    for (size_t i = 0; i < images.getSize(); i++) 
    {
        delete images.getImage(i);
    }

    images = ImageCollection();

    unsavedTransformations.clear();
}

void Session::copyFrom(const Session& other)
{
    sessionID = other.sessionID;
    images = other.images;
    unsavedTransformations = other.unsavedTransformations;
}

void Session::moveFrom(Session&& other)
{
    sessionID = other.sessionID;
    images = std::move(other.images);
    unsavedTransformations = std::move(other.unsavedTransformations);
}


Session::Session() : sessionID(++counterID) {}

Session::Session(const Session& other)
{
    copyFrom(other);
}

Session::Session(Session&& other) noexcept 
{
    moveFrom(std::move(other));
}

Session& Session::operator=(const Session& other) 
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Session& Session::operator=(Session&& other) noexcept 
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Session::~Session() 
{
    free();
}

void Session::addImage(Image* image) 
{
    images.addImage(image);
}



void Session::rotate(const String& direction) 
{
    for (size_t i = 0; i < images.getSize(); i++)
    {
        Image* img = images.getImage(i);

        if (direction == "left") 
        {
            img->rotateLeft();
        }
        else if (direction == "right") 
        {
            img->rotateRight();
        }
    }
    unsavedTransformations.pushBack("rotate " + direction);
}

void Session::grayscale() 
{
    for (size_t i = 0; i < images.getSize(); i++) 
    {
        images.getImage(i)->grayscale();
    }
    unsavedTransformations.pushBack("grayscale");
}

void Session::monochrome() 
{
    for (size_t i = 0; i < images.getSize(); i++) 
    {
        images.getImage(i)->monochrome();
    }
    unsavedTransformations.pushBack("monochrome");
}

void Session::negative() 
{
    for (size_t i = 0; i < images.getSize(); i++) 
    {
        images.getImage(i)->negative();
    }
    unsavedTransformations.pushBack("negative");
}


void Session::undo() 
{
    if (unsavedTransformations.empty()) 
    {
        throw std::runtime_error("No transformations to undo");
    }
    unsavedTransformations.popBack();
}

void Session::close()
{
    free();
    images = ImageCollection();
    unsavedTransformations = Vector<String>();
}



bool Session::containsFile(const String& fileLocation) const
{
    for (size_t i = 0; i < images.getSize(); i++) 
    {
        if (images.getImage(i)->getImageName() == fileLocation) 
        {
            return true;
        }
    }
    return false;
}

bool Session::hasUnsavedChanges() const 
{
    return !unsavedTransformations.empty();
}

int Session::getID() const 
{
    return sessionID;
}