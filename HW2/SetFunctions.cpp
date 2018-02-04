#include <sstream>

#include "SetFunctions.hpp"

void fillBag(ArrayBag& bag, std::ifstream& file)
{
    // Given a file and a bag, this function takes a line of inputs
    // from the file and stores them in the bag.
    std::string line;
    int input = 0;
    std::getline(file, line);
    std::istringstream iss(line);
    
    while (iss >> input)
    {
        bag.add(input);
    }
    
    // If the process stopped short of the end of iss, then there was an error
    // somewhere along the way. We'll assume that the input wasn't an int..
    if (!iss.eof())
    {
        std::cout << "Error: Non-integer value in input file. Exiting..\n";
        exit(1);
    }
}
