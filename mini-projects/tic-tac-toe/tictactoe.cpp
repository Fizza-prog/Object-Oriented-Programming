#include "tictactoe.h"

TicTacToe::TicTacToe() {
    restart();
}

void TicTacToe::initializeBoard() {
    char num = '1';
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = num++;
        }
    }
}

void TicTacToe::restart() {
    initializeBoard();
    currentPlayer = 'X';
    moveCount = 0;
    gameOver = false;
}

void TicTacToe::start() {
    restart();
}

bool TicTacToe::isValidMove(int position) const {
    if (position < 1 || position > 9) return false;
    
    int row = positionToRow(position);
    int col = positionToCol(position);
    
    return (board[row][col] != 'X' && board[row][col] != 'O');
}

bool TicTacToe::playMove(int position) {
    if (gameOver || !isValidMove(position)) {
        return false;
    }
    
    makeMove(position);
    moveCount++;
    
    if (checkWin()) {
        gameOver = true;
    } else if (checkDraw()) {
        gameOver = true;
    } else {
        switchPlayer();
    }
    
    return true;
}

void TicTacToe::makeMove(int position) {
    int row = positionToRow(position);
    int col = positionToCol(position);
    board[row][col] = currentPlayer;
}

bool TicTacToe::checkWin() const {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && 
            board[i][1] == board[i][2]) {
            return true;
        }
    }
    
    // Check columns
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == board[1][j] && 
            board[1][j] == board[2][j]) {
            return true;
        }
    }
    
    // Check diagonals
    if (board[0][0] == board[1][1] && 
        board[1][1] == board[2][2]) {
        return true;
    }
    
    if (board[0][2] == board[1][1] && 
        board[1][1] == board[2][0]) {
        return true;
    }
    
    return false;
}

bool TicTacToe::checkDraw() const {
    return moveCount >= 9;
}

void TicTacToe::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int TicTacToe::positionToRow(int pos) const {
    return (pos - 1) / SIZE;
}

int TicTacToe::positionToCol(int pos) const {
    return (pos - 1) % SIZE;
}

char TicTacToe::getBoardChar(int row, int col) const {
    return board[row][col];
}

bool TicTacToe::isGameOver() const {
    return gameOver;
}

char TicTacToe::getWinner() const {
    if (!gameOver || checkDraw()) return 'N';
    return (currentPlayer == 'X') ? 'X' : 'O';
}

char TicTacToe::getCurrentPlayer() const {
    return currentPlayer;
}

int TicTacToe::getMoveCount() const {
    return moveCount;
}

void TicTacToe::displayBoard() const {
    std::cout << "    +---+---+---+\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << "    | ";
        for (int j = 0; j < SIZE; j++) {
            std::cout << board[i][j] << " | ";
        }
        std::cout << "\n    +---+---+---+\n";
    }
}