/*
 * rps.cpp
 * Purpose:     A program that plays rock paper scissors with the user.
 * Modified by: Neil Powers
 * Bugs:        N/A
 */

#include <iostream>

// The following are for srand() and time()
// for random numbers. Leave them 
// in your program.
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROCK     = 0;
const int PAPER    = 1;
const int SCISSORS = 2;

void PlayRPS();
int GetHumanMove();
int GetComputerMove();
string WhoWins(int human_move, int computer_move);
void ReportWinner(string winner, int computer_move);

int main()
{
        srand(time(nullptr));

        // Starts a game of rock paper scissors.
        PlayRPS();
        
        return 0;
}

/* PlayRPS()
 * Parameters: None
 * Purpose:    Start a game of RPS.
 * Returns:    Nothing.
 * Effects:    Starts a console-based game of rock paper scissors.
 */
void PlayRPS()
{
        int human_move = GetHumanMove();
        int computer_move = GetComputerMove();

        string winner = WhoWins(human_move, computer_move);

        ReportWinner(winner, computer_move);
}

/* GetHumanMove
 * Parameters: None.
 * Purpose:    Get's the user's move and returns it as an integer.
 * Returns:    Rock, paper, or scissors returned as 0, 1, or 2 respectively.
 */
int GetHumanMove()
{
        string move;

        cout << "Enter rock (r), paper (p), or scissors (s): ";
        cin >> move;

        // Validates and returns move.
        if (move == "r" or move == "R") {
                return ROCK;
        } else if (move == "p" or move == "P") {
                return PAPER;
        } else if (move == "s" or move == "S") {
                return SCISSORS;
        } else {
                cout << "Please enter a valid move! Try again." << endl;
                return GetHumanMove();
        }
}

/* GetComputerMove
 * Parameters: None.
 * Purpose:    Get and return the computer's move.
 * Returns:    Rock, paper, or scissors returned as 0, 1, or 2 respectively.
 */
int GetComputerMove()
{
        return rand() % 3;
}

/* WhoWins
 * Parameters: The human move and the computer move.
 * Purpose:    Determine the winner based on the moved provided.
 * Returns:    "tie", "computer", or "human".
 */
string WhoWins(int human_move, int computer_move)
{
        if (human_move == computer_move)
        {
                return "tie";
        } else if (human_move == ROCK)
        {
                if (computer_move == PAPER) return "computer";
                else return "human";
        } else if (human_move == PAPER)
        {
                if (computer_move == SCISSORS) return "computer";
                else return "human";
        } else
        {
                if (computer_move == ROCK) return "computer";
                else return "human";
        }
}

/* PrintWinner
 * Parameters: The winner and the computer move.
 * Purpose:    Print the winner to the console.
 * Returns:    Nothing.
 */
void ReportWinner(string winner, int computer_move)
{
        // convert the computer move to a string.
        string computer_move_;
        if (computer_move == ROCK) computer_move_ = "rock";
        else if (computer_move == PAPER) computer_move_ = "paper";
        else computer_move_ = "scissors";

        // print the outcome.
        if (winner == "computer") cout << "You lost. ";
        else if (winner == "human") cout << "You won! ";
        else cout << "It's a tie. ";

        // print what the computer chose.
        cout << "The computer chose " << computer_move_ << "." << endl;
}
