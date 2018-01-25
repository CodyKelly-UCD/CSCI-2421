#include <algorithm>
#include <cstdlib>

#include "guess.hpp"

Guess::Guess() { }

void Guess::startNewGame(int m, int n)
{
    answers = std::vector<int>();
    
    for (int count = 0; count < n; count++)
    {
        answers.push_back((std::rand() % m) + 1);
    }
}

int Guess::guess(std::vector<int> g)
{
    int numberOfWrongGuesses = 0;
    
    // Check each of the player's guesses
    // If a guess isn't in the answers vector, increment number of wrong answers
    for (int i : g)
    {
        if(!(std::find(answers.begin(), answers.end(), i) != answers.end()))
        {
            numberOfWrongGuesses++;
        }
    }
    
    return numberOfWrongGuesses;
}
