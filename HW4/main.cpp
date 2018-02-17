#include <iostream>
#include <fstream>
#include <string>

#include "node1.h"
#include "functions.hpp"

using main_savitch_5::node;
using std::string;
using std::ifstream;

int main(int argc, char** argv)
{
    ifstream inputFile;
    std::string fileName;
    node* list = NULL;
    node* currentNode = list;
    
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
    catch (const ifstream::failure& e)
    {
        std::cout << "Exception opening/reading/closing file\n";
        exit(1);
    }

    list = getListFromFile(inputFile);
    currentNode = list;

    while (currentNode->link() != NULL)
    {
        std::cout << currentNode->data() << ' ';
        currentNode = currentNode->link();
    }
    std::cout << std::endl;
    
    // Get linked list of file contents
    
}
