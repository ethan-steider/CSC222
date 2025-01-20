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
uniform_int_distribution<int> diceValue(1, 3);

// Function prototypes

void displayChoice();
void playGame(char choice);
void keepScore(char winner);


void keepScore(string winner) {
    int humanScore = 0;
    int computerScore = 0; // start scores at 0
    if (winner == "Human wins") {
        humanScore == humanScore + 1; // adding score if human wins
        cout << "Human Score: " << humanScore << endl; // display scores
        cout << "Computer Score: " << computerScore << endl;
    }
    else if (winner == "Computer wins") {
        computerScore == computerScore + 1; // adding score if computer wins
        cout << "Human Score: " << humanScore << endl; // display scores
        cout << "Computer Score: " << computerScore << endl;
    }
    else {
        cout << "It's a draw!" << endl; // if it's a draw, display draw
    }
}

int playGame(string choice) {
    string computerWin = "Computer wins";
    string humanWin = "Human wins"; // set win conditions
    int computerchoice = diceValue(engine); // computer choice is random number

    if (choice == "Rock") { 
        if (computerchoice == 1) { // if random number is 1, it's a draw
            cout << "It's a draw!" << endl; //
        }
        else if (computerchoice == 2) { // if random number is 2, computer wins
            cout << "Computer wins" << endl;
            keepScore(computerWin);
        }
        else if (computerchoice == 3) { // if random number is 3, human wins
            cout << "You win" << endl;
            keepScore(humanWin);
        }
    }
    else if (choice == 'Paper') {
        if (computerchoice == 1) { // if random number is 1, human wins
            cout << "You win" << endl;
            keepScore(humanWin);
        }
        else if (computerchoice == 2) { // if random number is 2, it's a draw
            cout << "It's a draw!" << endl;
        }
        else if (computerchoice == 3) { // if random number is 3, computer wins
            cout << "Computer wins" << endl;
            keepScore(computerWin);
        }
    }
    else if (choice == 'Scissors') {
        if (computerchoice == 1) { // if random number is 1, computer wins
            cout << "Computer wins" << endl;
            keepScore(computerWin);
        }
        else if (computerchoice == 2) { // if random number is 2, human wins
            cout << "You win" << endl;
            keepScore(humanWin);
        }
        else if (computerchoice == 3) { // if random number is 3, it's a draw
            cout << "It's a draw!" << endl;
        }
    }
    else {
        cout << "It's a draw!" << endl; // if it's a draw, display draw
    }
    return computerchoice;
}

void displayChoice()
{
    string choice; // take user input
    cout << "Enter Rock, Paper, Scissors, or Quit: "; // prompts user to enter choice
    cin >> choice; // takes in chocie
    cout << "You chose: " << choice << endl; //tells user what they chose
    cout << "Computer chose: " << diceValue(engine) << endl; // tells user what computer chose
    if (choice == "Quit") {
        displayChoice(); // restarts game
    }
    else if (choice == "Rock") {
        playGame(choice); // plays game with choice rock
    }
    else if (choice == "Paper") {
        playGame(choice); //plays game with paper
    }
    else if (choice == "Scissors") {
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
