#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <cstdlib>
#include <windows.h>

// Forward declaration
class UIManager;

class TicTacToe {
private:
    static const int SIZE = 3;
    char board[SIZE][SIZE];
    char currentPlayer;
    int moveCount;
    bool gameOver;

    // Private helper methods
    void initializeBoard();
    bool isValidMove(int position) const;
    void makeMove(int position);
    bool checkWin() const;
    bool checkDraw() const;
    void switchPlayer();
    int positionToRow(int pos) const;
    int positionToCol(int pos) const;
    char getBoardChar(int row, int col) const;  // private رہے گا
    
    // UIManager کو friend بنائیں
    friend class UIManager;
    
public:
    TicTacToe();
    
    // Game control methods
    void start();
    void restart();
    bool isGameOver() const;
    char getWinner() const;
    char getCurrentPlayer() const;
    int getMoveCount() const;
    
    // Display methods
    void displayBoard() const;
    
    // Input methods
    bool playMove(int position);
};

#endif