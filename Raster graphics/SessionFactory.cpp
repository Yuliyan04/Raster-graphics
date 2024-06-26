#include "SessionFactory.h"

SessionFactory::SessionFactory() : currentSessionID(-1) {}

void SessionFactory::load(const String& fileName) 
{
    Image* newImage = ImageFactory::imageFactory(fileName);
    Session newSession;
    newSession.addImage(newImage);
    sessions.pushBack(newSession);
    currentSessionID = newSession.getID();
}

void SessionFactory::add(Image* image) 
{
    if (currentSessionID == -1) 
    {
        throw std::runtime_error("No active session");
    }
    getCurrentSession()->addImage(image);
}

void SessionFactory::switchSession(int sessionId) 
{
    for (size_t i = 0; i < sessions.getSize(); i++) 
    {
        if (sessions[i].getID() == sessionId)
        {
            currentSessionID = sessionId;
            return;
        }
    }
    throw std::runtime_error("Session ID not found");
}

void SessionFactory::grayscale()
{
    getCurrentSession()->grayscale();
}

void SessionFactory::monochrome() 
{
    getCurrentSession()->monochrome();
}

void SessionFactory::negative() 
{
    getCurrentSession()->negative();
}

void SessionFactory::rotate(const String& direction) 
{
    getCurrentSession()->rotate(direction);
}


void SessionFactory::save() 
{
    getCurrentSession()->save();
}

void SessionFactory::saveAs(const String& fileName) 
{
    getCurrentSession()->saveAs(fileName);
}

void SessionFactory::close()
{
    if (currentSessionID == -1) 
    {
        throw std::runtime_error("No active session");
    }
    getCurrentSession()->close();
    currentSessionID = -1;
}


Session* SessionFactory::getCurrentSession() 
{
    for (size_t i = 0; i < sessions.getSize(); i++) 
    {
        if (sessions[i].getID() == currentSessionID) 
        {
            return &sessions[i];
        }
    }
    throw std::runtime_error("Current session not found");
}

int SessionFactory::getCurrentSessionID() const
{
    return currentSessionID;
}