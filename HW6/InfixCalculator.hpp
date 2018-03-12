#ifndef InfixCalculator_hpp
#define InfixCalculator_hpp

#include <string>

class InfixCalculator
{
private:
    std::string to_postfix(std::string);    
public:
    std::string calculate(std::string);
};

#endif /* InfixCalculator_hpp */
