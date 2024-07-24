#include "Commands.h"


Commands::Commands() : sessionFactory() {}

void Commands::execute(const String& commandLine) 
{
    String ss(commandLine.c_str());
    String command;
    ss >> command;

    Command cmd;
    cmd.name = command;

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
        cmd.args.pushBack(direction);
        storeCommand(cmd);
    }
    else if (command == "grayscale") 
    {
        storeCommand(cmd);
    }
    else if (command == "monochrome")
    {
        storeCommand(cmd);
    }
    else if (command == "negative")
    {
        storeCommand(cmd);
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

void Commands::storeCommand(const Command& cmd)
{
    commandQueue.pushBack(cmd);
}

void Commands::applyCommands() 
{
    for (size_t i = 0; i < commandQueue.getSize(); i++)
    {
        const Command& cmd = commandQueue[i];

        if (cmd.name == "rotate")
        {
            rotate(cmd.args[0]);
        }
        else if (cmd.name == "grayscale") 
        {
            grayscale();
        }
        else if (cmd.name == "monochrome")
        {
            monochrome();
        }
        else if (cmd.name == "negative") 
        {
            negative();
        }
    }
    commandQueue.clear();
}

void Commands::save() 
{
    applyCommands();
    sessionFactory.save();
}

void Commands::saveAs(const String& fileName) 
{
    applyCommands();
    sessionFactory.saveAs(fileName);
}

void Commands::load(const String& fileName) 
{
    if (sessionFactory.getCurrentSessionID() != -1)
    {
        save();
        commandQueue.clear();
    }

    sessionFactory.load(fileName);
    std::cout << "Session with ID: " << sessionFactory.getCurrentSessionID() << " started." << std::endl;
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
    if (commandQueue.getSize() > 0) 
    {
        commandQueue.popBack();
        std::cout << "Last command undone." << std::endl;
    }
    else
    {
        std::cout << "No commands to undo." << std::endl;
    }
}

void Commands::switchSession(int sessionId)
{
    save();
    commandQueue.clear();
    sessionFactory.switchSession(sessionId);
}

void Commands::sessionInfo() const 
{
    std::cout << "Pending commands:" << std::endl;

    for (size_t i = 0; i < commandQueue.getSize(); i++)
    {
        std::cout << commandQueue[i].name.c_str();
        for (size_t j = 0; j < commandQueue[i].args.getSize(); j++)
        {
            std::cout << " " << commandQueue[i].args[j].c_str();
        }

        std::cout << std::endl;
    }
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

    std::cout<<"Image added to session successfully" << std::endl;
}