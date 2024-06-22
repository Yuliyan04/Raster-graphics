#pragma once
#include "Session.h"
#include "Vector.hpp"
#include "ImageFactory.h"
#include "Transformations.h"

class SessionFactory
{
private:
    Vector<Session> sessions;
    int currentSessionId;

public:
    SessionFactory();

    void load(const String& fileName);
    void add(Image* image);
    void switchSession(int sessionId);

    void grayscale();
    void monochrome();
    void negative();
    void rotate(const String& direction);

    void undo();
    void save();
    void saveAs(const String& fileName);
    void close();

    String getCurrentSessionInfo() const;
    bool hasUnsavedChanges() const;

private:
    Session* getCurrentSession();
};

