#include <iostream>
#include <fstream>
#include <list>
#include <string>

#include "DictEntry.hpp"
#include "dictionary.hpp"
#include "functions.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    ifstream dictFile, findFile;
    ofstream outFile;
    list<DictEntry> dictList;
    list<string> findList;
    dictionary dict;
    
    // Open files
    dictFile.open("dictionary.txt");
    findFile.open("findwords.txt");
    outFile.open("revsorted.txt");
    
    // Create lists from contents of files
    findList = getStringListFromFile(findFile);
    dictList = getEntryListFromFile(dictFile);
    
    // Search for contents of findList in dictionary front to back
    cout << "Searching dictionary front-to-back:\n";
    for (auto word : findList)
    {
        int count = dict.searchForward(dictList, word);
        
        cout << '"' << word << "\": ";
        
        if (count == -1)
        {
            cout << "not found.\n";
        }
        else
        {
            cout << "found in " << count;
            
            if (count == 1)
            {
                cout << " search.\n";
            }
            else
            {
                cout << " searches.\n";
            }
        }
        
        cout << endl;
    }
    
    // Search for contents of findList in dictionary back to front
    cout << "Searching dictionary back-to-front:\n";
    for (auto word : findList)
    {
        int count = dict.searchBackward(dictList, word);
        
        cout << '"' << word << "\": ";
        
        if (count == -1)
        {
            cout << "not found.\n";
        }
        else
        {
            cout << "found in " << count << " searches.\n";
        }
        
        cout << endl;
    }
    
    // Print out dictionary in reverse order into file
    dict.revPrintList(outFile, dictList);
    
    // Close files
    dictFile.close();
    findFile.close();
    outFile.close();
    
    return 0;
}
