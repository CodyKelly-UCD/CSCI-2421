#include <algorithm>
#include <vector>

#include "InfixCalculator.hpp"

std::string InfixCalculator::to_postfix(std::string infixExp)
{
    std::string postfixExp, operatorStack;
    
    for (auto ch : infixExp)
    {
        if (isnumber(ch))
        {
            postfixExp += ch;
        }
        else
        {
            operatorStack += ch;
        }
    }
    
    return postfixExp;
}

std::string InfixCalculator::calculate(std::string expression)
{
    std::string output;
    
    return output;
}
