#include <iostream>
#include <vector>
#include <limits>

#include "guess.hpp"

int getInput(int limit = 0)
{
    // This function asks the user to enter a number, checks the
    // input for validity and returns the result
    
    int input = 0;
    
    if (limit == 0)
    {
        std::cout << "Enter integer 1 or greater or enter -1 to quit: ";
        if (!(std::cin >> input) || input < -1)
        {
            std::cout << "\nInvalid input\n" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            input = getInput();
        }
    }
    else
    {
        std::cout << "Enter integer from 1 to " << limit << " or enter -1 to quit: ";
        
        if (!(std::cin >> input) || input < -1 || input > limit)
        {
            std::cout << "\nInvalid input\n" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            input = getInput(limit);
        }
    }
    
    std::cout << std::endl;
    
    if (input == -1)
    {
        exit(0);
    }
    
    return input;
}

bool getPlayAgain()
{
    // This function asks the user to type yes or no, checks the input for
    // validity and returns the result
    
    std::string input;
    char option;
    
    std::cout << "Play again? Yes or No: ";
    
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, input); // get full input
    
    option = tolower(input[0]); // extract choice from first character of string
    
    // If the first letter of the input isn't one of the valid options,
    // try again
    if (option != 'y' && option != 'n')
    {
        std::cout << "\nPlease type either yes or no.";
        std::cout << std::endl;
        return getPlayAgain();
    }
    
    return option == 'y';
}

int main()
{
    Guess guess;
    std::vector<int> guesses;
    int numberOfWrongGuesses = 0;
    int numberOfGuesses = 0;
    int range = 0;
    
    std::cout << "\nWelcome to Number Guess";
    
    do
    {
        std::cout << "\n\nPlease enter the total number of possible answers.\n";
        range = getInput();
        
        std::cout << "\nPlease enter the number of numbers to guess.\n";
        numberOfGuesses = getInput(range);
        
        guess.startNewGame(range, numberOfGuesses);
        
        do
        {
            guesses.clear();
            numberOfWrongGuesses = 0;
            
            for (int count = 0; count < numberOfGuesses; count++)
            {
                std::cout << "\n\nEnter guess #" << count + 1 << ": ";
                guesses.push_back(getInput(range));
            }
            
            numberOfWrongGuesses = guess.guess(guesses);
            
            if (numberOfWrongGuesses > 0)
            {
                std::cout << numberOfWrongGuesses << " of your guesses were wrong. Guess again.\n";
            }
        } while(numberOfWrongGuesses > 0);
        
        std::cout << "You win!\n";
    } while (getPlayAgain());
    
    return 0;
}
