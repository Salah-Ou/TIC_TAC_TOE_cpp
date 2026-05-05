#ifndef GAME_H
#define GAME_H
#include "utils.h"
#include <iostream>
#include <string>

using namespace std;

class Game {
    char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int row, column;
    char token = 'x';
    bool Tie = false;
    string name1, name2;

    public:
        // FIX 1 & 2: Added constructor to receive player names (removed bogus int main() member)
        Game(string n1, string n2) : name1(n1), name2(n2) {}

        void drawBoard();
        void takeInput();
        bool checkWin();
        void playGame();
};

#endif // GAME_H