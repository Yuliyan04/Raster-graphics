#include "Commands.h"

Commands::Commands() : sessionFactory() {}

void Commands::execute(const String& commandLine)
{
    std::istringstream iss(commandLine.c_str());
    String command;
    iss >> command;

    if (command == "load") 
    {
        String fileName;
        iss >> fileName;
        load(fileName);
    }
    else if (command == "save")
    {
        save();
    }
    else if (command == "saveas") 
    {
        String fileName;
        iss >> fileName;
        saveAs(fileName);
    }
    else if (command == "rotate") 
    {
        String direction;
        iss >> direction;
        rotate(direction);
    }
    else if (command == "grayscale") 
    {
        grayscale();
    }
    else if (command == "monochrome") 
    {
        monochrome();
    }
    else if (command == "negative") 
    {
        negative();
    }
    else if (command == "undo")
    {
        undo();
    }
    else if (command == "switch")
    {
        int sessionId;
        iss >> sessionId;
        switchSession(sessionId);
    }
    else if (command == "sessioninfo")
    {
        sessionInfo();
    }
    else 
    {
        std::cout << "Unknown command: " << command.c_str() << std::endl;
    }
}

void Commands::load(const String& fileName)
{
    sessionFactory.load(fileName);
}

void Commands::save()
{
    sessionFactory.save();
}

void Commands::saveAs(const String& fileName) 
{
    sessionFactory.saveAs(fileName);
}

void Commands::rotate(const String& direction) 
{
    sessionFactory.rotate(direction);
}

void Commands::grayscale()
{
    sessionFactory.grayscale();
}

void Commands::monochrome() 
{
    sessionFactory.monochrome();
}

void Commands::negative() 
{
    sessionFactory.negative();
}

void Commands::undo()
{
    sessionFactory.undo();
}

void Commands::switchSession(int sessionId)
{
    sessionFactory.switchSession(sessionId);
}

void Commands::sessionInfo() const 
{
    std::cout << sessionFactory.getCurrentSessionInfo() << std::endl;
}