#include <sstream>
#include <fstream>
#include <iostream>

#include "ArrayBag.hpp"
#include "SetFunctions.hpp"

int main()
{
    std::ifstream file;
    ArrayBag bag1, bag2;
    
    try
    {
        // Try opening the file and filling the bags.
        file.open("setInput.txt");
        fillBag(bag1, file);
        fillBag(bag2, file);
        file.close();
    }
    catch (const std::ifstream::failure& e)
    {
        std::cout << "Exception opening/reading/closing file\n";
        exit(1);
    }
    
    // Perform operations on the two bags and store the results of each in new
    // bags
    auto addBag = bag1 + bag2;
    auto subBag = bag1 - bag2;
    
    // Output results for the user to see.
    std::cout << "Bag 1: " << bag1 << "\nBag 2: " << bag2 << std::endl;
    std::cout << "Union bag: " << addBag << "\nDifference bag: " << subBag << std::endl;
    
    return 0;
}
