#include <iostream>
#include <fstream>
#include <string>

#include "node1.h"

using main_savitch_5::node;
using std::string;

string getWordFromFile()
{
    string word;
    
    
    
    return word;
}

node* getListFromFile()
{
    node* head = new node;
    
    
    
    return head;
}

int main(int argc, char** argv)
{
    std::ifstream inputFile;
    std::string fileName;
    
    // Open file
    if (argc > 1)
    {
        fileName = argv[1]; // Open file given by command line parameter, if available
    }
    else
    {
        fileName = "data.txt"; // Otherwise, open "data.txt"
    }
    try
    {
        inputFile.open(fileName);
    }
    catch (const std::ifstream::failure& e)
    {
        std::cout << "Exception opening/reading/closing file\n";
        exit(1);
    }
    
    // Get linked list of file contents
    
}
