// File: CS112_A1_T5_20230022.cpp
// Purpose: two players start at 0 and take turns adding numbers from 1 to 10 to a total. The first one to reach 100 wins.
// Author: Ahmed Shaaban Maghraby
// Section: not registered yet 
// ID: 20230022
// Version: 1.0
// Date: 1/3/2023


#include <iostream>
#include <limits> // Needed for input validation

using namespace std;

void Play_100_game() {
    // Greet the players with a welcome message.
    cout << "Welcome to the 100 game!" << endl;

    int score = 0; // This will keep track of the cumulative score.
    int playerInput = 0; // This variable stores the player's input each turn.
    string currentPlayer; // Keeps track of who's turn it is.

    // The game continues until the score reaches or exceeds 100.
    while (score < 100) {
        // Each player takes turns, so we loop through player 1 and player 2.
        for (int player = 1; player <= 2; ++player) {
            currentPlayer = "Player " + to_string(player); // Updating the current player.
            do {
                cout << currentPlayer << ", enter a number from 1 to 10: ";
                cin >> playerInput;

                // If the input is invalid or not in the expected range, prompt again.
                if (cin.fail() || playerInput < 1 || playerInput > 10) {
                    cout << "That's not a valid input. Please enter a number between 1 and 10." << endl;
                    cin.clear(); // Clears the error flag on cin.
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discards the incorrect input.
                    playerInput = 0; // Reset playerInput to ensure the prompt is repeated.
                }
            } while (playerInput < 1 || playerInput > 10); // Keep asking until a valid input is given.

            score += playerInput; // Add the player's valid input to the total score.

            // Check if this player's addition has reached or exceeded the score of 100.
            if (score >= 100) {
                cout << currentPlayer << " wins the game!" << endl; // Declare the winner.
                return; // End the game function as we have a winner.
            }
        }
    }
}

int main() {
    // Start the game by calling the Play_100_game function.
    Play_100_game();
    return 0; // Indicates that the program ended successfully.
}
