#include "functions.hpp"

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

ifstream& getWord(ifstream& fin, string& w)
{
    char c;
    
    w = ""; // clear the string of characters
    
    while (fin.get(c) && !isalpha(c)); // do nothing. just ignore c
    
    // return on end-of-file
    if (fin.eof())
        return fin;
    
    // record first letter of the word
    w += tolower(c);
    
    // collect letters and digits
    while (fin.get(c) && (isalpha(c) || isdigit(c) || ispunct(c)))
    {
        if (isalpha(c) || isdigit(c))
        {
            w += tolower(c);
        }
    }
    
    return fin;
}
