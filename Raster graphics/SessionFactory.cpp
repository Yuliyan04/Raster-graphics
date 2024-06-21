#include "SessionFactory.h"

SessionFactory::SessionFactory() : currentSessionId(-1) {}

void SessionFactory::loadSession(const String& fileName) 
{
    Image* newImage = ImageFactory::imageFactory(fileName);
    Session newSession;
    newSession.addImage(newImage);
    sessions.pushBack(newSession);
    currentSessionId = newSession.getID();
}

void SessionFactory::addImageToCurrentSession(Image* image) 
{
    if (currentSessionId == -1) 
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
            currentSessionId = sessionId;
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

void SessionFactory::undo() 
{
    getCurrentSession()->undo();
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
    if (currentSessionId == -1) 
    {
        throw std::runtime_error("No active session");
    }
    getCurrentSession()->close();
    currentSessionId = -1;
}


Session* SessionFactory::getCurrentSession() 
{
    for (size_t i = 0; i < sessions.getSize(); i++) 
    {
        if (sessions[i].getID() == currentSessionId) 
        {
            return &sessions[i];
        }
    }
    throw std::runtime_error("Current session not found");
}

String SessionFactory::getCurrentSessionInfo() const 
{
    if (currentSessionId == -1) 
    {
        throw std::runtime_error("No current session.");
    }

    return sessions[currentSessionId].info();
}

bool SessionFactory::hasUnsavedChanges() const 
{
    if (currentSessionId == -1)
    {
        throw std::runtime_error("No current session.");
    }
    return sessions[currentSessionId].hasUnsavedChanges();
}