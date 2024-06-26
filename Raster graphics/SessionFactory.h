#pragma once
#include "Session.h"
#include "Vector.hpp"
#include "ImageFactory.h"
#include "Transformations.h"

class SessionFactory
{
private:
    Vector<Session> sessions;
    int currentSessionID;

public:
    SessionFactory();

    void load(const String& fileName);
    void add(Image* image);
    void switchSession(int sessionId);

    void grayscale();
    void monochrome();
    void negative();
    void rotate(const String& direction);

    void save();
    void saveAs(const String& fileName);
    void close();

    int getCurrentSessionID() const;

private:
    Session* getCurrentSession();
};

