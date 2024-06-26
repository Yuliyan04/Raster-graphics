#pragma once
#include "SessionFactory.h"


class Commands
{
private:
    SessionFactory sessionFactory;

public:
    Commands();

    void add(const String& fileName); //
    void execute(const String& commandLine); //
    void load(const String& fileName); //
    void save(); //
    void saveAs(const String& fileName); 
    void rotate(const String& direction); //
    void grayscale(); //
    void monochrome(); //
    void negative(); //
    void undo();
    void switchSession(int sessionID);
    void sessionInfo() const;
};

