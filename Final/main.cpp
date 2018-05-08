
#include <iostream>
#include <string>
#include <fstream>

#include "functions.hpp"
#include "actorActressTreeFunctions.hpp"

void mainMenu(actorActressTree *aaTree)
{
    int menuChoice = 0;
    string menuString =
    "Would you like to:\n"
    "1) View the actor/actress database\n"
    "2) View the movie database\n"
    "3) Exit";
    clearScreen();
    menuChoice = getInput(menuString, 3);
    
    switch (menuChoice)
    {
        case 1:
            aaDatabaseMenu(aaTree);
            break;
            
        case 2:
            break;
            
        case 3:
            exit(1);
            break;
            
        default:
            break;
    }
}

int main()
{
    actorActressTree *aaTree = new actorActressTree;
    
    getAADataFromFile(aaTree);
    
    while (true)
    {
        mainMenu(aaTree);
        
        auto thing = aaTree->findNode("derp");
        if (thing != nullptr)
        {
            clearScreen();
            cout << "found derp";
            cin.get();
        }
        else
        {
            clearScreen();
            cout << "did not find derp";
            cin.get();
        }
    }
    
    return 0;
}
