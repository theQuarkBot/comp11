/* guess.cpp
 * Purpose:     Asks the user to guess a random number a number of times.
 * Modified by: Neil Powers
 * Date:        02/21/21
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_TRIES   = 3;
const int LOWER_BOUND = 5;
const int UPPER_BOUND = 15;

int GetRandomNumber(int lower, int upper);
void GuessNum(int num, int num_tries);
int GetGuess();
 
int main()
{
        srand(time(nullptr));

        // Produces a random number within the specified bounds.
        int rand_num = GetRandomNumber(LOWER_BOUND, UPPER_BOUND);

        // Asks user to guess random number within a number of tries.
        GuessNum(rand_num, MAX_TRIES);
        
        return 0;
}

/* GetRandomNumber
 * Parameters: An upper and lower bound.
 * Purpose:    Return a random number within the upper and lower bound.
 */
int GetRandomNumber(int lower, int upper)
{
        int range = upper - lower;
        return rand() % (range + 1) + lower;
}

/* GuessNum
 * Parameters: The random number (num) and the number of tries (num_tries)
 * Purpose:    Have the user guess a random number num_tries times
 * Results:    Whether its the correct guess
 * Effects:    Console prints.
 */
void GuessNum(int num, int num_tries)
{
        int guess = GetGuess();

        // Decreases the number of remaining tries by one.
        --num_tries;

        // If wrong and out of tries, else if too low, else if too high, correct
        if (guess != num and num_tries < 1) {
                cout << "The number was " << num
                                << ". Better luck next time" << endl;
        } else if (guess < num) {
                cout << "That was too low. ";
                GuessNum(num, num_tries);
        } else if (guess > num) {
                cout << "That was too high. ";
                GuessNum(num, num_tries);
        } else {
                cout << "You guessed it! Good job!" << endl;
        }
}

/* GetGuess
 * Parameters: None.
 * Purpose:    Return an integer the user guesses.
 * Results:    An integer guessed by the user.
 * Effects:    Console print and input.
 */
int GetGuess()
{
        int out;

        cout << "Enter a guess: ";
        cin >> out;

        return out;
}
