
#include <iostream>
#include <string>
#include <fstream>

#include "functions.hpp"

int main()
{
    ifstream aaFile("actor-actress.csv"), nFile("nominations.csv");
    BSTree<vector<awardStruct> *, string> *aaTree = new BSTree<vector<awardStruct> *, string>;
    
    getAADataFromFile(aaFile, aaTree);
    
    aaTree->printInorder();
    
    return 0;
}
