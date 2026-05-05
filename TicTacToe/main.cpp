#include "game.h"
#include <iostream>
#include <string>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else
#include <unistd.h>
#include <termios.h>
#endif

using namespace std;

int main() {
    // FIX 2: Declare name1 & name2 as local variables here (they were used
    // before without any declaration — the private Game members are not
    // accessible from outside the class).
    string name1, name2;

    clear_screen();
    Time();
    gotoxy(34, 2);
    cout << CYAN << "==== Welcome To Tic Tac Toe Game! ====";
    gotoxy(36, 4);
    cout << CYAN << "    Enter Player 1 Name : \033[1;37m";
    getline(cin, name1);
    gotoxy(36, 6);
    cout << CYAN << "    Enter Player 2 Name : \033[1;37m";
    getline(cin, name2);
    cout << RESET;

    // Pass the names into the Game constructor instead of assigning to
    // inaccessible private members.
    Game game(name1, name2);
    game.playGame();
    return 0;
}