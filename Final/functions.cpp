#include "functions.hpp"

bool debug = false;

int getInput(string message)
{
    int input;
    
    cout << message << endl;
    cout << "Enter an integer 0 or greater or enter -1 to quit: ";
    
    if (!(cin >> input) || input < -1)
    {
        cout << "\nInvalid input\n";
        cin.clear();
        cin.ignore();
        input = getInput(message);
    }
    
    if (input == -1)
    {
        exit(0);
    }
    
    return input;
}

int getInput(string message, int limit)
{
    int input;
    
    cout << message << endl;
    cout << "Enter an integer from 1 to " << limit << " or enter -1 to quit: ";
    
    if (!(cin >> input) || input < -1 || input == 0 || input > limit)
    {
        cout << "\nInvalid input\n" << endl;
        cin.clear();
        cin.ignore();
        clearScreen();
        input = getInput(message, limit);
    }
    
    if (input == -1)
    {
        exit(0);
    }
    
    return input;
}

bool getBoolFromFile(ifstream &infile, char delim = ',')
{
    bool b = false;
    
    string boolstr;
    getline(infile, boolstr, delim);
    if (boolstr == "1")
    {
        b = true;
    }
    
    return b;
}

int getIntFromFile(ifstream &infile, char delim = ',')
{
    string tempString;
    int tempInt;
    getline(infile, tempString, delim);
    tempInt = stoi(tempString);
    return tempInt;
}

float getFloatFromFile(ifstream &infile, char delim = ',')
{
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

vector<actorActressData> getAADataFromFile(ifstream& file, BSTree<vector<awardStruct> *, string> *aaTree)
{
    vector<actorActressData> aadata;
    
    // Ignore first line of file
    file.ignore(numeric_limits<streamsize>::max(), '\n');
    
    while (!file.eof())
    {
        actorActressData newData;
        
        // Get year from file
        newData.year = getIntFromFile(file);
        
        // Get award name
        getline(file, newData.award, ',');
        
        // Get winner bool
        newData.winner = getBoolFromFile(file);
        
        // Get the name of the actor/actress who was considered
        getline(file, newData.name, ',');
        
        // Finally, get name of film
        getline(file, newData.film, '\n');
        
        // If there was a comma at the end of the film, we can ignore it
        if (newData.film.back() == ',')
        {
            newData.film.pop_back();
        }
        
        // Ignore the rest of the line
        eat_white(file);
        
        aadata.push_back(newData);
    }
    
    for (auto data : aadata)
    {
        awardStruct newAward;
        newAward.filmName = data.film;
        newAward.year = data.year;
        newAward.winner = data.winner;
        newAward.awardName = data.award;
        
        // Find actor
        auto actor = aaTree->findNode(data.name);
        if (actor == nullptr)
        {
            // If the actor doesn't exist yet, make a new one
            vector<awardStruct> *awards = new vector<awardStruct>;
            awards->push_back(newAward);
            aaTree->addNode(data.name, awards);
        }
        else
        {
            actor->Data()->push_back(newAward);
        }
    }
    
    return aadata;
}
