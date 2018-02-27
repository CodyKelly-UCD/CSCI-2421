#include <iostream>

#include "functions.hpp"

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
    
    return word;
}

main_savitch_5::node* getListFromFile(std::ifstream &ifile)
{
    // Stores contents of data file into a linked list
    main_savitch_5::node* head = new main_savitch_5::node;  // First element
    main_savitch_5::node* lastNode = head;                  // Stores previous element in list
    
    head->set_data(getWordFromFile(ifile));                 // Get first word
    
    while (ifile)
    {
        // While there's more in data file, create new elements to hold data
        // and link the new elements to each other
        main_savitch_5::node* newNode = new main_savitch_5::node;
        lastNode->set_link(newNode);
        newNode->set_data(getWordFromFile(ifile));
        lastNode = newNode;
    }
    
    return head;
}

void printList(main_savitch_5::node * const head)
{
    // Prints a linked list element by element with spaces in between
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

void sortList(main_savitch_5::node*& head)
{
    main_savitch_5::node* unSortedHead = head->link();      // First element in unsorted portion
    main_savitch_5::node* currentPtr = head;                // Our current position in the sorted list
    main_savitch_5::node* newSorted = NULL;                 // Used to store temporary node pointers
    main_savitch_5::node* prevSorted = NULL;
    
    head->set_link(NULL);
    
    while(unSortedHead != NULL)                 // If we haven't hit the end of the unsorted portion
    {
        while (tolowerstring(unSortedHead->data()) > tolowerstring(currentPtr->data()))
        // Compare the next unsorted element with each sorted element
        // Also covert both strings to lowercase form for more accurate comparison
        {
            if (currentPtr->link() == NULL)     // If we've hit the end of the sorted list then stop
            {
                break;
            }
            else                                // Else we continue through the list
            {
                prevSorted = currentPtr;        // Save the element we just left
                currentPtr = currentPtr->link();// Continue to next element
            }
        }
        
        newSorted = unSortedHead;               // Now that we know the position, save address for linking
        unSortedHead = unSortedHead->link();    // Continue to the next unsorted element
        newSorted->set_link(currentPtr);        // Link the new element to the next in sorted list
        if (prevSorted == NULL)                 // If we're at the front of the sorted portion
        {
            head = newSorted;                   // Make the new element the head
        }
        else
        {
            prevSorted->set_link(newSorted);   // If we're not at the front, link the previous
                                                // element to the new one
        }
        prevSorted = NULL;                      // Reset the previous element to NULL for next loop
        currentPtr = head;                // Reset the currentPtr to head
    }
}
