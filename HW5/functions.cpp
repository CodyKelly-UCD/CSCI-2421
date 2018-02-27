#include <iostream>

#include "functions.hpp"

std::string tolowerstring(std::string originalString)
{
    // returns a completely lowercase version
    std::string newString;
    for (auto c : originalString)
    {
        newString += tolower(c);
    }
    
    return newString;
}

void eat_white(std::ifstream& ifile)
{
    while (ifile && isspace(ifile.peek()))
        ifile.ignore();
}

std::string getWordFromFile(std::ifstream &ifile)
{
    // This function returns the next string of consecutive non-whitespace
    // characters from a file
    std::string word;
    char nextChar;
    
    eat_white(ifile);   // Ignore whitespace
    
    while (ifile)       // If we're not at the end of the file
    {
        nextChar = ifile.get(); // get the next char
        if (isalpha(nextChar))  // Make sure it's not whitespace
        {
            word += nextChar;   // add it to word
        }
        else                    // if it was whitespace
        {
            break;              // then we're done
        }
    }
    
    eat_white(ifile); // ignore extra whitespace after word
    
    return word;
}

std::list<DictEntry> getEntryListFromFile(std::ifstream &ifile)
{
    std::list<DictEntry> newList;
    
    while (ifile)
    {
        // While there's more in data file, create new elements to hold data
        DictEntry newEntry;
        newEntry.setWord(getWordFromFile(ifile));
        newList.push_back(newEntry);
    }
    
    newList.sort();
    return newList;
}

std::list<std::string> getStringListFromFile(std::ifstream &ifile)
{
    std::list<std::string> newList;
    
    while (ifile)
    {
        // While there's more in data file, create new elements to hold data
        newList.push_back(getWordFromFile(ifile));
    }
    
    newList.sort();
    return newList;
}
