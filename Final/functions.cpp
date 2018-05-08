#include <limits>

#include "functions.hpp"
#include "Node.h"

bool debug = false;

int getInput(string message, int maxOption, int minOption)
{
    int input;
    
    cout << message << endl;
    cout << "Enter a number from " << minOption << " to " << maxOption << ": ";
    
    if (!(cin >> input) || input < minOption || input > maxOption)
    {
        cout << "\nInvalid input. Press enter to continue.\n" << endl;
        cin.get();
        cin.clear();
        cin.ignore();
        input = getInput(message, minOption, maxOption);
    }
    
    return input;
}

int getInput(string message, int maxOption)
{
    return getInput(message, maxOption, 1);
}

bool getBoolFromFile(ifstream &infile)
{
    bool b = false;
    char delim = ',';
    
    string boolstr;
    getline(infile, boolstr, delim);
    if (boolstr == "1")
    {
        b = true;
    }
    
    return b;
}

int getIntFromFile(ifstream &infile)
{
    char delim = ',';
    string tempString;
    int tempInt;
    getline(infile, tempString, delim);
    tempInt = stoi(tempString);
    return tempInt;
}

float getFloatFromFile(ifstream &infile)
{
    char delim = ',';
    string tempString;
    float tempFloat;
    getline(infile, tempString, delim);
    tempFloat = stof(tempString);
    return tempFloat;
}

void clearScreen()
{
    // Outputs a bunch of newlines, effectively "clearing" the screen
    int count = 500;
    
    if (debug)
    {
        count = 5;
    }
    
    while (count > 0)
    {
        cout << endl;
        count--;
    }
}

void eat_white(std::ifstream& ifile)
{
    while (ifile && isspace(ifile.peek()))
        ifile.ignore();
}

int getYearFromUser()
{
    int year = 0;
    while (year == 0)
    {
        clearScreen();
        cout << "Enter a new year: ";
        cin.ignore();
        if (!(cin >> year))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max());
            year = 0;
        }
    }
    return year;
}

bool getBoolFromUser()
{
    bool b = false;
    if (getInput("Please enter a 1 for yes, or 2 for no:", 2) == 1)
    {
        b = true;
    }
    return b;
}

std::string tolower(std::string originalString)
{
    // returns a completely lowercase version
    std::string newString;
    for (auto c : originalString)
    {
        newString += tolower(c);
    }
    
    return newString;
}
