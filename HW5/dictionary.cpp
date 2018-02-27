#include "dictionary.hpp"

int dictionary::searchForward(list<DictEntry> &wordList, wordType &findString)
{
    int count = 0;
    for (auto it = wordList.begin(); it != wordList.end(); it++, count++)
    {
        if (it->getWord() == findString)
        {
            return count;   // return number of elements searched
        }
    }
    
    return -1;  // If the given string was not found, return -1
}

int dictionary::searchBackward(list<DictEntry> &wordList, wordType &findString)
{
    int count = 0;
    for (auto it = wordList.rbegin(); it != wordList.rend(); it++, count++)
    {
        if (it->getWord() == findString)
        {
            return count;   // return number of elements searched
        }
    }
    
    return -1;  // If the given string was not found, return -1
}

void dictionary::revPrintList(ostream &output, list<DictEntry> &wordList)
{
    // sort list in reverse order
    wordList.sort(greater<wordType>());
    
    // print elements
    for (auto it = wordList.rbegin(); it != wordList.rend(); it++)
    {
        cout << it->getWord();
        cout << ' ';
    }
    cout << endl;
}
