#include <iostream>
#include <random>
using namespace std;

// Requirements for the game
// ***********************************************
// Program should loop until user decides to quit
// Random number 1-3 1 is rock 2 is paper 3 is scissors
// Human enters "Rock", "Paper", "Scissors" or "Quit"
// Program compares human input to random number and determines winner
// if both are the same, it's a draw
//`***********************************************

// Random number engine
random_device engine;
 
// Distribution object
uniform_int_distribution<int> dist(1, 3);

// Function prototypes

void displayChoice();
void playGame(char choice);
void keepScore(char winner);
void displayScore(char winner);



void playGame(char choice) {


}

void displayChoice()
{
    char choice; // take user input
    cout << "Enter Rock, Paper, Scissors, or Quit: "; // prompts user to enter choice
    cin >> choice; // takes in chocie
    cout << "You chose: " << choice << endl; //tells user what they chose
    if (choice == 'Quit') {
        displayChoice(); // restarts game
    }
    else if (choice == 'Rock') {
        playGame(choice); // plays game with choice rock
    }
    else if (choice == 'Paper') {
        playGame(choice); //plays game with paper
    }
    else if (choice == 'Scissors') {
        playGame(choice); // plays game with scissors
    }
}

int main()
{
    char choice; // take user input
    displayChoice(); // display choice
    playGame(choice); // plays game with choice
    return 0;
}
