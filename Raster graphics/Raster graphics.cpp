#include <iostream>
#include "Commands.h"
#include "String.h"


void printMenu() 
{
    std::cout << "\n";
    std::cout << "|============================================|\n";
    std::cout << "|              Raster graphics               |\n";
    std::cout << "|============================================|\n";
    std::cout << "|1. Load image - load                        |\n";
    std::cout << "|2. Add image - add                          |\n";
    std::cout << "|3. Switch session - switch<sessionID>       |\n";
    std::cout << "|4. Undo transformation - undo               |\n";
    std::cout << "|5. Save changes - save                      |\n";
    std::cout << "|6. Save as new file - saveas                |\n";
    std::cout << "|7. Session info - info                      |\n";
    std::cout << "|8.Transformations:                          |\n";                        
    std::cout << "|  -negative                                 |\n";
    std::cout << "|  -grayscale                                |\n";
    std::cout << "|  -monochrome                               |\n";
    std::cout << "|  -rotate <left/right>                      |\n";
    std::cout << "|9. Exit - exit                              |\n";
    std::cout << "|============================================|\n";
    std::cout << "\n";
    std::cout << "> ";
}
//

int main()
{
    Commands commandHandler;
    String input;

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

