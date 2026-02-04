#include "tictactoe.h"
#include "uimanager.h"
#include "soundmanager.h"
#include <iostream>

int main() {
    TicTacToe game;
    bool playAgain = true;

    while (playAgain) {
        UIManager::clearScreen();

        SoundManager::playSound(SoundManager::WELCOME);
        UIManager::displayTitle();
        UIManager::displayInstructions();

        std::cout << "    Press Enter to start...";
        std::cin.ignore();
        std::cin.get();

        SoundManager::playSound(SoundManager::GAME_START);
        game.start();

        while (!game.isGameOver()) {
            UIManager::clearScreen();
            UIManager::displayTitle();

            std::cout << "\n    Move #" << game.getMoveCount() + 1 << "\n";
            std::cout << "    ============\n\n";
            std::cout << "    Current Player: " << game.getCurrentPlayer() << "\n\n";

            UIManager::displayBoard(game);

            bool validMove = false;
            while (!validMove) {
                int position;

                std::cout << "    Enter position (1-9): ";
                std::cin >> position;

                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "    (~ x_x)~  Invalid input! Enter numbers 1-9 only.\n";
                    SoundManager::playSound(SoundManager::ERROR_SOUND);
                    continue;
                }

                if (position < 1 || position > 9) {
                    std::cout << "    (~ x_x)~  Invalid! Enter 1-9 only.\n";
                    SoundManager::playSound(SoundManager::ERROR_SOUND);
                    continue;
                }

                if (game.playMove(position)) {
                    SoundManager::playSound(SoundManager::MOVE_PLACED);
                    validMove = true;
                }
                else {
                    std::cout << "    Position " << position << " already taken!\n";
                    SoundManager::playSound(SoundManager::ERROR_SOUND);
                }
            }
        }

        UIManager::clearScreen();
        UIManager::displayTitle();
        UIManager::displayResult(game);
        UIManager::displayBoard(game);

        if (game.getWinner() == 'N') {
            SoundManager::playSound(SoundManager::DRAW);
        }
        else {
            SoundManager::playSound(SoundManager::WIN);
        }

        playAgain = UIManager::askPlayAgain();
    }

    UIManager::clearScreen();
    UIManager::displayExitMessage();
    SoundManager::playSound(SoundManager::EXIT);

    std::cout << "    Press Enter to exit...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}