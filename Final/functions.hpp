#ifndef Functions_hpp
#define Functions_hpp

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#include "dataTypes.hpp"
#include "BSTree.h"
#include "BSTree.hpp"

using namespace std;

int getInput(string, int, int);

void clearScreen();

void eat_white(std::ifstream& ifile);

vector<actorActressData> getAADataFromFile(ifstream& file, BSTree<vector<awardStruct> *, string> *aaTree);

void aaDatabaseMenu(actorActressTree *);

void mainMenu(actorActressTree *);

#endif /* Functions_hpp */
