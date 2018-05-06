#include <iostream>
#include <unordered_set>
#include <string>
#include <fstream>
#include <vector>

#include "functions.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    unordered_set<string> dictionary, misspelledWords;
    ifstream dictFile, inputFile;
    string iFileName;
    int numWordsInInput = 0, totalMisspelledWords = 0;
    
    dictFile.open("dict.txt");
    
    // Tell user if there was an error while opening dict file and exit
    if (dictFile.fail())
    {
        cout << "Error while opening dictionary file.\nExiting...\n";
        return 1;
    }
    
    dictionary.rehash(1373);                // Set number of buckets
    
    // Fill dictionary
    while (!dictFile.eof())
    {
        string newEntry;
        getWord(dictFile, newEntry);
        newEntry = tolower(newEntry);
        if (newEntry != "\n")               // Ignore newline at end
        {
            dictionary.insert(newEntry);
        }
    }
    
    // Get input filename from user
    cout << "Please enter filename and press enter (format: fileName.txt): ";
    getline(cin, iFileName);
    inputFile.open(iFileName);
    
    // Tell user if there was an error while opening dict file and exit
    if (inputFile.fail())
    {
        cout << "Error while opening input file.\nExiting...\n";
        return 1;
    }
    
    // Test each word in file for spelling errors
    string word;
    while (!inputFile.eof())
    {
        numWordsInInput++;
        getWord(inputFile, word);
        
        if (word != "")                   // Ignore empty strings
        {
            word = tolower(word);
            auto result = dictionary.find(word);
            
            // If the word was not found in the dictionary, add it to the list
            // of misspelled words.
            if (result == dictionary.end())
            {
                misspelledWords.insert(word);
                totalMisspelledWords++;
            }
        }
    }
    
    
    // Output results
    cout << "Possible misspelled words:\n";
    
    if (misspelledWords.size() == 0)
    {
        cout << "None! Impeccable spelling.\n";
    }
    else
    {
        for (auto word: misspelledWords)
        {
            cout << word << endl;
        }
    }
    
    cout << "\nNumber of words in dictionary: " << dictionary.size() << endl;
    cout << "Number of words in input file: " << numWordsInInput << endl;
    cout << "Number of unique misspellings: " << misspelledWords.size() << endl;
    cout << "Total number of misspellings: " << totalMisspelledWords << endl;
    
    return 0;
}
