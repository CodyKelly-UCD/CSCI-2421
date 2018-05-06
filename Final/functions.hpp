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

int getInput(string message);

int getInput(string message, int limit);

void clearScreen();

void eat_white(std::ifstream& ifile);

vector<actorActressData> getAADataFromFile(ifstream& file, BSTree<vector<awardStruct> *, string> *aaTree);

#endif /* Functions_hpp */
