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
int playGame(string choice);
void keepScore(string winner);
int computerchoice = diceValue(engine); // random number generator

int humanScore = 0;
int computerScore = 0; // start scores at 0

void keepScore(string winner) {
    if (winner == "Human wins") {
        humanScore = humanScore + 1; // adding score if human wins
        cout << "Human Score: " << humanScore << endl; // display scores
        cout << "Computer Score: " << computerScore << endl;
    }
    else if (winner == "Computer wins") {
        computerScore = computerScore + 1; // adding score if computer wins
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
    int computerchoice = diceValue(engine); // random number generator
    if (computerchoice == 1) {
        cout << "Computer chose: Rock" << endl; // tells user what computer chose
    }
    else if (computerchoice == 2) {
        cout << "Computer chose: Paper" << endl; // tells user what computer chose
    }
    else if (computerchoice == 3) {
        cout << "Computer chose: Scissors" << endl; // tells user what computer chose
    }

    if (choice == "Rock") { 
        if (computerchoice == 1) { // if random number is 1, it's a draw
            cout << "It's a draw!" << endl; //
            displayChoice();
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
    else if (choice == "Paper") {
        if (computerchoice == 1) { // if random number is 1, human wins
            cout << "You win" << endl;
            keepScore(humanWin);
        }
        else if (computerchoice == 2) { // if random number is 2, it's a draw
            cout << "It's a draw!" << endl;
            displayChoice();
        }
        else if (computerchoice == 3) { // if random number is 3, computer wins
            cout << "Computer wins" << endl;
            keepScore(computerWin);
        }
    }
    else if (choice == "Scissors") {
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
            displayChoice();
        }
    }
    return computerchoice;
}

int main() {
    displayChoice(); // start game
    return 0;
}
void displayChoice() {
    string choice; // take user input
    cout << "Enter Rock, Paper, Scissors, or Quit: "; // prompts user to enter choice
    cin >> choice; // takes in chocie
    cout << "You chose: " << choice << endl; //tells user what they chose
    if (choice == "Quit") {
        cout << "Final Scores" << endl;
        cout << "Human Score: " << humanScore << endl;
        cout << "Computer Score: " << computerScore << endl;
        main(); // if user enters quit, display scores and end game
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
    else {
        cout << "Invalid choice" << endl; // if user enters invalid choice, display invalid choice
    }
    displayChoice(); // loop back to start
}


