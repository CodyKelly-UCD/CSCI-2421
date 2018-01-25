#ifndef guess_hpp
#define guess_hpp

#include <vector>

class Guess
{
private:
    std::vector<int> answers;
    int numberOfGuesses = 0;
public:
    Guess();
    void startNewGame(int, int);
    int guess(std::vector<int>);
};

#endif /* guess_hpp */
