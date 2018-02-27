#ifndef functions_hpp
#define functions_hpp
#include <string>
#include <fstream>
#include <list>

#include "DictEntry.hpp"

void eat_white(std::ifstream& ifile);
std::string getWordFromFile(std::ifstream &ifile);
std::list<DictEntry> getEntryListFromFile(std::ifstream &ifile);
std::list<std::string> getStringListFromFile(std::ifstream &ifile);
std::string tolowerstring(std::string);

#endif /* functions_hpp */
