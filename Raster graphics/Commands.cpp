#include "Commands.h"

Commands::Commands() : sessionFactory() {}

void Commands::execute(const String& commandLine) 
{
    std::stringstream ss(commandLine.c_str());
    String command;
    ss >> command;

    if (command == "load") 
    {
        String fileName;
        ss >> fileName;
        load(fileName);
    }
    else if (command == "save") 
    {
        save();
    }
    else if (command == "saveas") 
    {
        String fileName;
        ss >> fileName;
        saveAs(fileName);
    }
    else if (command == "rotate")
    {
        String direction;
        ss >> direction;
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
        ss >> sessionId;
        switchSession(sessionId);
    }
    else if (command == "info") 
    {
        sessionInfo();
    }
    else if (command == "add") 
    {
        String fileName;
        ss >> fileName;
        add(fileName);
    }
    else 
    {
        std::cout << "Unknown command: " << command.c_str() << std::endl;
    }
}

void Commands::load(const String& fileName)
{
    sessionFactory.load(fileName);
    std::cout << "Session with ID: " << sessionFactory.getCurrentSessionID() << " started." << std::endl;
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
    sessionFactory.undo(); //fix 
}

void Commands::switchSession(int sessionId)
{
    sessionFactory.switchSession(sessionId);
}

void Commands::sessionInfo() const 
{
    std::cout << sessionFactory.getCurrentSessionInfo() << std::endl; //fix
}

void Commands::add(const String& fileName) 
{
    Image* newImage = ImageFactory::imageFactory(fileName);

    if (!newImage) 
    {
        std::cout << "Error: Failed to load image from file: " << fileName << std::endl;
        return;
    }

    sessionFactory.add(newImage);
    std::cout << "Image \"" << fileName.c_str() << "\" added to session " << sessionFactory.getCurrentSessionID() << std::endl;
}