#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include "tictactoe.h"

class UIManager {
private:
    static void setColor(int color);
    
public:
    static void clearScreen();
    static void displayTitle();
    static void displayInstructions();
    static void displayBoard(const TicTacToe& game);
    static void displayResult(const TicTacToe& game);
    static int getPlayerInput();
    static bool askPlayAgain();
    static void displayExitMessage();
};

#endif