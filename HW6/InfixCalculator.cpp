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
            if (operatorStack.length() == 0)    // If operator stack is empty
            {
                operatorStack += ch;            // Add operator to stack
            }
            else                                // If the stack isn't empty
            {
                switch (ch)
                {
                    case '*':
                    case '/':
                    {
                        bool end = false;
                        char nextOperator = '\0';
                        
                        while (!end)
                        {
                            // Get the next operator on the stack
                            nextOperator = operatorStack.back();
                            
                            // End is true if the next operator is an open
                            // parenthese or an operator of lesser precedence
                            end =   nextOperator == '(' ||
                                    nextOperator == '+' ||
                                    nextOperator == '-' ||
                                    operatorStack.length() == 1;
                            
                            if (!end) // If we haven't found an operator like that
                            {
                                // Then we remove the operator from the stack
                                operatorStack.pop_back();
                                // And add it to the postfix expression
                                postfixExp += nextOperator;
                            }
                        }
                        
                        // Now we're done and we can add the current operator
                        // to the operator stack.
                        operatorStack += ch;
                        break;
                    }
                        
                    case '+':
                    case '-':
                    {
                        bool end = false;
                        char nextOperator = '\0';
                        
                        while (!end)
                        {
                            // Get the next operator on the stack
                            nextOperator = operatorStack.back();
                            
                            // End is true if the next operator is an open
                            // parenthesis
                            end =   nextOperator == '(' ||
                                    operatorStack.length() == 1;
                        
                            if (!end) // If we haven't found an operator like that
                            {
                                // Then we remove the operator from the stack
                                operatorStack.pop_back();
                                // And add it to the postfix expression
                                postfixExp += nextOperator;
                            }
                        }
                        
                        // Now we're done and we can add the current operator
                        // to the operator stack.
                        operatorStack += ch;
                        break;
                    }
                    
                    case '(':
                    {
                        // Push open parenthesis to stack
                        operatorStack += ch;
                        break;
                    }
                    
                    case ')':
                    {
                        // Pop operands to stack until we find a closing parenthesis
                        while (operatorStack.back() != '(')
                        {
                            postfixExp += operatorStack.back();
                            operatorStack.pop_back();
                        }
                        
                        // Pop closing parenthesis off
                        operatorStack.pop_back();
                        
                        break;
                    }
                        
                    default:
                        break;
                }
            }
        }
    }
    
    // Add remaining operators to postfix expression
    for (auto it = operatorStack.rbegin(); it != operatorStack.rend(); it++)
    {
        postfixExp += *it;
    }
    
    return postfixExp;
}

int InfixCalculator::calculate_postfix(std::string expression)
{
    std::vector<int> stack;
    int result = 0;
    
    for(auto ch : expression)
    {
        // If we hit a number, push onto stack
        if (isnumber(ch))
        {
            stack.push_back((int)ch - 48);  // Convert char to int
        }
        else
        {
            int n1 = 0, n2 = 0;
            
            // Get operands and pop them from stack
            n2 = stack.back();
            stack.pop_back();
            n1 = stack.back();
            stack.pop_back();
            
            switch (ch)
            {
                case '+':
                    result = n1 + n2;
                    break;
                    
                case '-':
                    result = n1 - n2;
                    break;
                    
                case '*':
                    result = n1 * n2;
                    break;
                    
                case '/':
                    result = n1 / n2;
                    break;
                    
                default:
                    break;
            }
            
            stack.push_back(result);
        }
    }
    
    return result;
}
