#ifndef SetFunctions_hpp
#define SetFunctions_hpp

#include <fstream>

#include "ArrayBag.hpp"

// This function takes a bag and a file. It fills the bag with the contents
// of the current line in the file.
void fillBag(ArrayBag& bag, std::ifstream& file);

#endif /* SetFunctions_hpp */
