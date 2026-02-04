#include "uimanager.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>

void UIManager::setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void UIManager::clearScreen() {
    system("cls");
}

void UIManager::displayTitle() {
    setColor(13);
    std::cout << "\n    ==========================\n";
    std::cout << "       TIC TAC TOE  \\(^,_,^)/\n";
    std::cout << "    ==========================\n";

    setColor(14);
    std::cout << "    Player X: ";
    setColor(10);
    std::cout << "X";
    setColor(14);
    std::cout << "  |  Player O: ";
    setColor(12);
    std::cout << "O\n";
    setColor(7);
}

void UIManager::displayInstructions() {
    setColor(11);
    std::cout << "\n    HOW TO PLAY  (- ^~^)-\n";
    std::cout << "    =====================\n\n";
    setColor(15);
    std::cout << "    1. Use numbers 1-9 to select position\n";
    std::cout << "    2. X goes first, then O\n";
    std::cout << "    3. Get 3 in a row to win!\n\n";

    std::cout << "    Board Positions:\n";
    std::cout << "    +---+---+---+\n";
    std::cout << "    | 1 | 2 | 3 |\n";
    std::cout << "    +---+---+---+\n";
    std::cout << "    | 4 | 5 | 6 |\n";
    std::cout << "    +---+---+---+\n";
    std::cout << "    | 7 | 8 | 9 |\n";
    std::cout << "    +---+---+---+\n\n";
}

void UIManager::displayBoard(const TicTacToe& game) {
    std::cout << "    +---+---+---+\n";
    for (int i = 0; i < 3; i++) {
        std::cout << "    | ";
        for (int j = 0; j < 3; j++) {
            char cell = game.getBoardChar(i, j);
            if (cell == 'X') {
                setColor(10);
                std::cout << cell;
                setColor(11);
            }
            else if (cell == 'O') {
                setColor(12);
                std::cout << cell;
                setColor(11);
            }
            else {
                setColor(15);
                std::cout << cell;
                setColor(11);
            }
            std::cout << " | ";
        }
        std::cout << "\n    +---+---+---+\n";
    }
    std::cout << "\n";
    setColor(7);
}

void UIManager::displayResult(const TicTacToe& game) {
    setColor(11);
    std::cout << "\n    GAME OVER!\n";
    std::cout << "    ===========\n\n";

    if (game.getWinner() == 'X') {
        setColor(10);
        std::cout << "     ==========================  \n";
        std::cout << "     \\(*0*)/  PLAYER X WINS!\n";
        std::cout << "     ========================== \n\n";
    }
    else if (game.getWinner() == 'O') {
        setColor(12);
        std::cout << "      =========================\n";
        std::cout << "      \\(^o^)/  PLAYER O WINS!\n";
        std::cout << "      =========================\n\n";
    }
    else {
        setColor(14);
        std::cout << "    =======================\n";
        std::cout << "     (/ 0o0)/  IT'S A DRAW!\n";
        std::cout << "    =======================\n\n";
    }
}

bool UIManager::askPlayAgain() {
    char choice;
    setColor(14);
    std::cout << "\n    ";
    for (int i = 0; i < 30; i++) std::cout << "=";
    std::cout << "\n    <(^,_,^)-?  Play again? (Y/N): ";
    std::cin >> choice;
    std::cin.ignore(1000, '\n');
    return (choice == 'Y' || choice == 'y');
}

void UIManager::displayExitMessage() {
    clearScreen();
    setColor(10);
    std::cout << "\n    =============================\n";
    std::cout << "    Thanks for playing!  \\(^_^)/\n";
    std::cout << "    =============================\n\n";
    setColor(7);
}