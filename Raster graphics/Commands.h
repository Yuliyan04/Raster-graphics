#pragma once
#include "SessionFactory.h"


struct Command 
{
    String name;
    Vector<String> args;
};



class Commands
{
private:
    Vector<Command> commandQueue;
    SessionFactory sessionFactory;

public:
    Commands();
    void execute(const String& commandLine);
    void storeCommand(const Command& cmd);
    void applyCommands();
    void load(const String& fileName);
    void save();
    void saveAs(const String& fileName);
    void rotate(const String& direction);
    void grayscale();
    void monochrome();
    void negative();
    void undo(); 
    void switchSession(int sessionId); 
    void sessionInfo() const;
    void add(const String& fileName);
};

