/*
 Homework 3
 CSCI 2421
 Cody Kelly
 2-7-18
 main.cpp
 */

#include <iostream>
#include <fstream>

#include "mystring.h"

int getIntInput()
{
    // This function asks the user for an integer of value 1 or greater.
    // It will continue to ask the user for input if invalid input is entered.
    // If the user enters -1, the program will end.
    int input;
    
    std::cout << "Enter a line length 1 or greater or enter -1 to quit: ";
    
    if (!(std::cin >> input) || input < -1 || input == 0)
    {
        std::cout << "\nInvalid input\n";
        std::cin.clear();
        std::cin.ignore();
        input = getIntInput();
    }
    
    std::cout << std::endl;
    
    if (input == -1)
    {
        exit(0);
    }
    
    return input;
}

void getFileContents(std::ifstream &inputFile, hw4::my_string &text)
{
    // This function reads in input from a file, while ignoring any extra
    // whitespace
    while (inputFile)
    {
        if (isspace(inputFile.peek()))      // If the next character is whitespace
        {
            if (inputFile.get() == '\n')    // If it's a newline, add the newline
            {
                text += '\n';
            }
            
            hw4::eat_white(inputFile, text);// Ignore any whitespace after
            text += ' ';
        }
        
        text += inputFile.get();
    }
}

hw4::my_string formatString(hw4::my_string const str, int lineLength)
{
    // Takes a string and formats it to fit within specific line lengths
    // and removes extra whitespace.
    // If a line ends on a character that isn't a whitespace character, or if
    // the character after that isn't whitespace,
    // this function adds a hyphen.
    
    hw4::my_string formattedString = ""; // Holds the results of formatting

    for (int index = 0, index_f = 0; index_f < str.length() - 1; index++, index_f++)
    {
        // index keeps track of the current index in the un-formatted string.
        // We use index to know when to end lines (if the current index is a
        // multiple of the lineLength, we know we're at the end of a line.)
        
        // index_f keeps track of which character we're considering currently
        // in the format process. Sometimes we need to skip whitespace if it
        // occurs at the end of a line. When we do, we need a seperate index
        // to keep track of our position in the formatting process.
        
        
        if ((index + 1) % (lineLength) == 0)        // If we're at the end of
        {                                           // a line:
            if (isspace(str[index_f]))              // First check if the current
            {                                       // char is whitespace
                formattedString += '\n';            // If so, replace with newline
            }
            else if (isspace(str[index_f + 1]))     // If the beginning of the
            {                                       // next line is whitespace:
                formattedString += str[index_f];    // Add the current char to the formatted string
                formattedString += '\n';            // Add a newline
                index_f++;                          // Then skip the whitespace at the beginning of the next line
            }
            else                                    // If neither the current char
            {                                       // or the next is whitespace:
                formattedString += str[index_f];    // Add the current char to the formatted string
                formattedString += "-\n";           // Then add a hyphen and newline
            }
        }
        else                                        // If we're in the middle of a line:
        {                                           // Add whatever char we're on to the
            formattedString += str[index_f];        // formatted text
        }
    }
    
    return formattedString;                          // Return formatted text
}

int main(int argc, char** argv)
{
    char const* fileName;
    std::ifstream inputFile;
    std::ofstream outputFile;
    hw4::my_string text, formattedText;
    int lineLength = 0;
    
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
    
    outputFile.open("data.out");
    
    lineLength = getIntInput();                         // get format line length from user
    getFileContents(inputFile, text);                   // store input into text
    formattedText = formatString(text, lineLength);     // format text
    
    std::cout << std::endl << formattedText << std::endl;
    outputFile << formattedText;
    
    inputFile.close();
    outputFile.close();
    
    return 0;
}
