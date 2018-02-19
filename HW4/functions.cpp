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

void printList(main_savitch_5::node * const head)
{
    main_savitch_5::node* currentNode = head;
    while (currentNode->link() != NULL)
    {
        std::cout << currentNode->data() << ' ';
        currentNode = currentNode->link();
    }
    std::cout << currentNode->data() << std::endl;  // Print last element
}

void openFile(int argc, char** argv, std::ifstream& ifile)
{
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
        ifile.open(fileName);
    }
    catch (const std::ifstream::failure& e)
    {
        std::cout << "Exception opening/reading/closing file\n";
        exit(1);
    }
}

void sortList(main_savitch_5::node* head)
{
    main_savitch_5::node* sortedHead = head;                // First element in sorted portion
    main_savitch_5::node* unSortedHead = head->link();      // First element in unsorted portion
    main_savitch_5::node* currentPtr = head;                // Our current position in the sorted list
    main_savitch_5::node* nextSorted = NULL;                // Used to store temporary node pointers
    
    sortedHead->set_link(NULL);
    
    while(unSortedHead != NULL)                     // If we haven't hit the end of the unsorted portion
    {
        while (unSortedHead->data() > currentPtr->data())   // Compare the next unsorted element with each sorted element
        {
            if (currentPtr->link() == NULL)                 // If we've hit the end of the sorted list then we make the current unsorted element the end
            {
                break;
            }
            else
            {
                currentPtr = currentPtr->link();
            }
        }
        
        nextSorted = currentPtr->link();                    // If we've found a sorted element less than the current unsorted element
                                                            // then we save the element after the current sorted element in memory
                                                            // so we can link it back to the sorted list later
        currentPtr->set_link(unSortedHead);                 // Set the current list link to the unsorted element
        unSortedHead = unSortedHead->link();                // Set the unsorted element portion head to the next unsorted element
        currentPtr->link()->set_link(nextSorted);           // Set the element after the current sorted element (the one we just added)'s link to
                                                            // the pointer we saved earlier
        currentPtr = sortedHead;                            // Go back to the start of the sorted list
    }
}
