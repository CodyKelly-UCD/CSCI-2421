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

int getInput(string message, int);

int getInput(string message, int, int);

bool getBoolFromFile(ifstream &infile);

int getIntFromFile(ifstream &infile);

float getFloatFromFile(ifstream &infile);

void clearScreen();

void eat_white(std::ifstream& ifile);

int getYearFromUser();

bool getBoolFromUser();

std::string tolower(std::string originalString);

#endif /* Functions_hpp */
