#include <iostream>

const char EMPTY = ' ';
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';

void displayBoard(const char board[3][3]) {
    std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << std::endl;
    std::cout << "---+---+---" << std::endl;
    std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << std::endl;
    std::cout << "---+---+---" << std::endl;
    std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << std::endl;
}

bool isBoardFull(const char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

bool checkWin(const char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

void getMove(int &row, int &col) {
    std::cout << "Enter row (0, 1, 2) and column (0, 1, 2): ";
    std::cin >> row >> col;
}

int main() {
    char board[3][3];
    char currentPlayer;
    bool gameOngoing;

    do {
        // Initialize the game
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = EMPTY;
            }
        }
        currentPlayer = PLAYER_X;
        gameOngoing = true;

        while (gameOngoing) {
            displayBoard(board);

            int row, col;
            bool validMove = false;

            while (!validMove) {
                getMove(row, col);

                if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == EMPTY) {
                    board[row][col] = currentPlayer;
                    validMove = true;
                } else {
                    std::cout << "Invalid move. Try again." << std::endl;
                }
            }

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                gameOngoing = false;
            } else if (isBoardFull(board)) {
                displayBoard(board);
                std::cout << "The game is a draw!" << std::endl;
                gameOngoing = false;
            } else {
                // Switch player
                currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
            }
        }

        std::cout << "Do you want to play again? (y/n): ";
        char playAgain;
        std::cin >> playAgain;
        if (playAgain != 'y' && playAgain != 'Y') {
            break;
        }

    } while (true);

    return 0;
}
