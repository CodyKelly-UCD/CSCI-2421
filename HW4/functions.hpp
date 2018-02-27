#ifndef functions_hpp
#define functions_hpp
#include <string>
#include <fstream>

#include "node1.h"

class ExceptionFirstWordNotFound {};
void eat_white(std::ifstream& ifile);
std::string getWordFromFile(std::ifstream &ifile);
main_savitch_5::node* getListFromFile(std::ifstream &ifile);
void printList(main_savitch_5::node *const);
void openFile(int argc, char** argv, std::ifstream& ifile);
main_savitch_5::node* searchForSubList(std::string, std::string);
void sortList(main_savitch_5::node*&);

#endif /* functions_hpp */
