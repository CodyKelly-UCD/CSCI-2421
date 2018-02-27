/*
 This program does the following:
 1) Makes a linked list of words from a file
 2) Takes two strings from user
 3) Searches for a node in the original list containing the first string
 4) Searches for a node after the first node containing the second string
 5) Makes a sublist containing copies of all nodes from the first up to and including the last
 6) Sorts the sublist by dictionary order
 */

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
    string word1, word2;
    node    *listHead = NULL,                           // Head of the original list
            *subListHead = new main_savitch_5::node,    // Head of the sublist
            *subListTail = new main_savitch_5::node,    // Tail of sublist
            *firstSearch = NULL,                        // Pointer to results of first search
            *secondSearch = NULL;                       // Pointer to results of seconds search

    // Make and print original list
    openFile(argc, argv, inputFile);
    listHead = getListFromFile(inputFile);
    printList(listHead);
    
    // Get input and search for a sublist
    // If either of the searches return NULL, alert user and exit program
    std::cout << "\nPlease enter the first word to search for: ";
    getline(std::cin, word1, ' ');
    firstSearch = main_savitch_5::list_search(listHead, word1);
    if (firstSearch == NULL)
    {
        std::cout << "Sublist not found\n";
        return 0;
    }
    std::cout << "\nPlease enter the second word to search for: ";
    getline(std::cin, word2, ' ');
    secondSearch = main_savitch_5::list_search(firstSearch, word2);
    if (secondSearch == NULL)
    {
        std::cout << "Sublist not found\n";
        return 0;
    }
    std::cout << std::endl;
    
    // Make and print sublist
    main_savitch_5::list_piece(firstSearch, secondSearch, subListHead, subListTail);
    printList(subListHead);
    
    // Sort and print sublist
    sortList(subListHead);
    printList(subListHead);
    
    return 0;
}
