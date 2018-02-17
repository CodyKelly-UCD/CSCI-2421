#include <iostream>

#include "functions.hpp"

void eat_white(std::ifstream& ifile)
{
    while (ifile && isspace(ifile.peek()))
        ifile.ignore();
}

std::string getWordFromFile(std::ifstream &ifile)
{
    std::string word;
    char nextChar;
    
    eat_white(ifile);
    
    while (ifile)
    {
        nextChar = ifile.get();
        if (isalpha(nextChar))
        {
            word += nextChar;
        }
        else
        {
            break;
        }
    }
    
    return word;
}

main_savitch_5::node* getListFromFile(std::ifstream &ifile)
{
    main_savitch_5::node* head = new main_savitch_5::node;
    main_savitch_5::node* lastNode = head;
    
    head->set_data(getWordFromFile(ifile));
    
    while (ifile)
    {
        main_savitch_5::node* newNode = new main_savitch_5::node;
        lastNode->set_link(newNode);
        newNode->set_data(getWordFromFile(ifile));
        lastNode = newNode;
    }
    
    return head;
}
