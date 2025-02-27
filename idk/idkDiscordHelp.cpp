#include <iostream>

int main(){

    while(true)
    {
        int i{1};
        int guess{getGuess(i)};
        
        std::cout << "Enter guess #" << i << ": \n";
        
        if(guess==number)
        {
            std::cout << "You won the game!\n";
            break;
        }
        else if(i>guess)
        {
            std::cout << "You lost the game...\n";
            break;
        }
        else if(guess>number)
        {
            std::cout << "Your guess is too high.\n";
        }
        else
        {
            std::cout << "Your guess is too low.\n";
        }
        
        ++i;
    }
}
