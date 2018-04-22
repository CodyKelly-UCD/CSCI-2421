#ifndef InfixCalculator_hpp
#define InfixCalculator_hpp

#include <string>

class InfixCalculator
{
public:
    std::string to_postfix(std::string);
    int calculate_postfix(std::string);
};

#endif /* InfixCalculator_hpp */
