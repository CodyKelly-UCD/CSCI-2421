#ifndef functions_hpp
#define functions_hpp
#include <string>
#include <fstream>

#include "node1.h"

void eat_white(std::ifstream& ifile);
std::string getWordFromFile(std::ifstream &ifile);
main_savitch_5::node* getListFromFile(std::ifstream &ifile);

#endif /* functions_hpp */
