#include "dictionary.hpp"

int dictionary::searchForward(list<DictEntry> &wordList, wordType &findString)
{
    int count = 0;
    
    
    
    return count;
}

int dictionary::searchBackward(list<DictEntry> &wordList, wordType &findString)
{
    int count = 0;
    
    
    
    return count;
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
