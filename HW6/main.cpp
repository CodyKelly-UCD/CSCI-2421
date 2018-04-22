/*
 TODO:
 Implement a driver function that takes one line of infix expression either
 from console or an input file infix.dat, and print out the post fix expression
 and calculated result to the console.
 */

#include <iostream>
#include <string>
#include <fstream>

#include "InfixCalculator.hpp"

using namespace std;

void driver()
{
    InfixCalculator calculator;
    string expression, post_expr;
    ifstream file("infix.dat");
    
    getline(file, expression);
    
    // If we didn't get an expression from the file, we'll get it from the user:
    if (expression.length() == 0)
    {
        cout << "Please enter an expression: ";
        getline(cin, expression);
        cout << endl;
    }
    
    post_expr = calculator.to_postfix(expression);
    
    cout << "Expression: " << expression << endl;
    cout << "Postfix form: " << post_expr << endl;
    cout << "Result: " << calculator.calculate_postfix(post_expr) << endl;
}

int main()
{
    driver();
    
    return 0;
}
