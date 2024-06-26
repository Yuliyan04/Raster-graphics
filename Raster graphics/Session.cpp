#include "Session.h"


int Session::counterID = 0;



Session::Session() : sessionID(++counterID) {}

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

void Session::close()
{
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

void Session::save()
{
    for (size_t i = 0; i < images.getSize(); i++)
    {
        ImageFactory::writeImage(images.getImage(i), images.getImage(i)->getImageName());
    }
    unsavedTransformations.clear();
}

void Session::saveAs(const String& fileName)
{
    if (images.getSize() == 0) 
    {
        throw std::runtime_error("No images to save");
    }

    ImageFactory::writeImage(images.getImage(0), fileName);
    unsavedTransformations.clear();
}
