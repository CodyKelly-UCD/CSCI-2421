#ifndef functions_hpp
#define functions_hpp

#include <string>
#include <fstream>

using namespace std;

std::string tolower(std::string originalString);

ifstream& getWord(ifstream& fin, string& w);

#endif /* functions_hpp */
