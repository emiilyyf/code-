#include <iostream>
#include <string>

using namespace std;

// Im using char to position the board
char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player = 'X';

void displayBoard() {
    cout << "\n";
    cout << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "---+---+---\n";
    cout << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "---+---+---\n";
    cout << board[6] << " | " << board[7] << " | " << board[8] << "\n";
}

//This switches the player between X and O 
//I asked chatGPT to help me write this line of code
void switchPlayer() {
    player = (player == 'X') ? 'O' : 'X';
}

//this function checks if the game is won
bool checkWin() {
    return (board[0] == board[1] && board[1] == board[2]) ||
    (board[3] == board[4] && board[4] == board[5]) ||
    (board[6] == board[7] && board[7] == board[8]) ||
    (board[0] == board[3] && board[3] == board[6]) ||
    (board[1] == board[4] && board[4] == board[7]) ||
    (board[2] == board[5] && board[5] == board[8]) ||
    (board[0] == board[4] && board[4] == board[8]) ||
    (board[2] == board[4] && board[4] == board[6]);
}

// this checks if the board full for a tie 
bool isBoardFull() {
    for (int i = 0; i < 9; i++ ) {
        if (board[i] != 'X' && board[i] != 'O') return false;
    }
    return true;
}

int main() {
    int move;
    bool gameWon = false;
    string result;

    cout << "Tic Tac Toe\n";
    displayBoard();

    // this is the main loop
    while (!gameWon && !isBoardFull()) {
        cout << "Player " << player << ", make your move.";
        cin >> move;

        //checking to see if the mvoes are valid
        if (move >= 1 && move <= 9 && board[move - 1] != 'X' && board[move -1] != 'O') {
            board[move - 1] = player;
            displayBoard();
            gameWon = checkWin(); // checking for a win 

            if (!gameWon) {
                switchPlayer(); // this switches to the other player 
            }
        } else {
            cout << "Invalid. Try again.\n";
        }
    }

    // checks to see if the game is won or tied
    if (gameWon) {
        result = "Player " + string(1, player) + " wins!";
        cout << result << "\n";
    } else {
        result = "The game is Tied!";
        cout << result << "\n";
    }

    return 0;
} 

