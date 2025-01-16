#include <iostream>
#include <random>
using namespace std;

// Program should loop until user decides to quit
// Random number 1-3 1 is rock 2 is paper 3 is scissors
// Human enters "Rock", "Paper", "Scissors" or "Quit"
// Program compares human input to random number and determines winner
// if both are the same, it's a draw


// Function prototypes

void displayChoice();
void playGame(char choice);



void displayChoice()
{
    char choice; // take user input
    cout << "Enter Rock, Paper, Scissors, or Quit: "; // prompts user to enter choice
    cin >> choice; // takes in chocie
    cout << "You chose: " << choice << endl; //tells user what they chose
    if (choice == 'Quit') {
        playGame(choice); // plays game with choice

    }
}

int main()
{
    char choice;
    displayChoice();
    playGame(choice);
    return 0;
}
