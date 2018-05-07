
#include <iostream>
#include <string>
#include <fstream>

#include "functions.hpp"



int main()
{
    ifstream aaFile("actor-actress.csv"), nFile("nominations.csv");
    actorActressTree *aaTree = new actorActressTree;
    
    getAADataFromFile(aaFile, aaTree);
    
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
