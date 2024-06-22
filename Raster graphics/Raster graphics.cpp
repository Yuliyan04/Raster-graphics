#include <iostream>
#include "Commands.h"
#include "String.h"


void printMenu() 
{
    std::cout << "Raster Graphics Editor\n";
    std::cout << "======================\n";
    std::cout << "1. Load image - load\n";
    std::cout << "2. Add image - add\n";
    std::cout << "3. Switch session - switch<sessionID>\n";
    std::cout << "4. Undo transformation\n";
    std::cout << "5. Save changes - save\n";
    std::cout << "6. Save as new file - saveas\n";
    std::cout << "7. Session info - info\n";
    std::cout << "8. Exit - exit\n";
    std::cout << "Enter your choice: ";
}


int main()
{
    Commands commandHandler;
    std::string input;

    while (true) 
    {
        printMenu();
        std::getline(std::cin, input);

        if (input == "9" || input == "exit") 
        {
            break;
        }

        String commandInput(input.c_str());
        commandHandler.execute(commandInput);
    }
}

