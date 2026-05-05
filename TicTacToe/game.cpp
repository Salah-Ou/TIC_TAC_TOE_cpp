#include "game.h"
#include "utils.h"
#include <iostream>
#include <string>

void Game::drawBoard() {
    clear_screen();
    gotoxy(34, 0);
    Time();
    gotoxy(30, 2); cout << CYAN << "====== Tic Tac Toe Game ======" ;
    gotoxy(33, 4); cout << GREEN << name1 << " (x)" ; gotoxy(50,4); cout << "Player 1" ;
    gotoxy(33, 6); cout << RED << name2 << " (o)" ; gotoxy(50,6); cout << "Player 2" << endl ;
    cout << CYAN << "\n\t\t\t\t    ___________________\n";
    cout << CYAN << "\t\t\t\t    |     |     |     |\n";
    for (int i = 0; i < 3; i++) {
        cout << CYAN << "\t\t\t\t    |  ";
        for (int j = 0; j < 3; j++) {
            if (space[i][j] == 'x') {
                cout << GREEN << space[i][j] << CYAN << "";
            } else if (space[i][j] == 'o') {
                cout << RED << space[i][j] << CYAN << "";
            } else {
                cout << space[i][j];
            }
            cout << "  |  ";
        }
        cout << CYAN << "\n\t\t\t\t    |_____|_____|_____|\n";
        if (i < 2) {
            cout << CYAN << "\t\t\t\t    |     |     |     |\n";
        }
    }
    cout << "\n";
}

void Game::takeInput() {
    while (true) {
        int digit;
        if (token == 'o') {
            gotoxy(38, 19); cout << RED << "==) " << name2 ;
            gotoxy(35, 20); cout << "---------------------";
            gotoxy(35, 21); cout << "Enter your digit : " << RESET ;
        } else {
            gotoxy(38, 19); cout << GREEN << "==) " << name1 ;
            gotoxy(35, 20); cout << "---------------------";
            gotoxy(35, 21); cout << "Enter your digit : " << RESET;
        }
        if (!(cin >> digit) || digit < 1 || digit > 9) {
            cin.clear();
            cin.ignore(1000, '\n');
            gotoxy(35, 23); cout << RED << "Invalid Choice...  !! \n" ;
            sleep_seconds(1);
            gotoxy(33, 21); cout << CLEAN_LINE ;
            gotoxy(34, 23); cout << CLEAN_LINE ;
            continue ;
        }

        row    = (digit - 1) / 3;
        column = (digit - 1) % 3;

        if (space[row][column] != 'x' && space[row][column] != 'o') {
            space[row][column] = token;
            token = (token == 'x') ? 'o' : 'x';
            return;
        } else {
            gotoxy(33, 23); cout << RED << "Position Already Occupied ! \n" ;
            gotoxy(33, 21); cout << CLEAN_LINE ;
            gotoxy(30, 23); cout << CLEAN_LINE ;
            sleep_seconds(1);
        }
    }
}

bool Game::checkWin() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (space[i][0] == space[i][1] && space[i][1] == space[i][2] &&
            (space[i][0] == 'x' || space[i][0] == 'o'))
            return true;
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (space[0][i] == space[1][i] && space[1][i] == space[2][i] &&
            (space[0][i] == 'x' || space[0][i] == 'o'))
            return true;
    }
    // Check diagonals
    if (space[0][0] == space[1][1] && space[1][1] == space[2][2] &&
        (space[1][1] == 'x' || space[1][1] == 'o'))
        return true;
    if (space[0][2] == space[1][1] && space[1][1] == space[2][0] &&
        (space[1][1] == 'x' || space[1][1] == 'o'))
        return true;

    // Check for Tie (all positions filled)
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (space[i][j] != 'x' && space[i][j] != 'o')
                return false;

    Tie = true;
    return true;
}

void Game::playGame() {
    while (true) {
        while (true) {
            drawBoard();
            takeInput();
            if (checkWin()) {
                drawBoard();
                if (Tie) {
                    gotoxy(40, 19);
                    cout << "\033[1;33mIt's a Tie!" << RESET ;
                } else if (token == 'x') {
                    gotoxy(40, 19);
                    cout << RED << name2 << " WON!" << RESET ;
                } else {
                    gotoxy(40, 19);
                    cout << GREEN << name1 << " WON!" << RESET;
                }
                break;
            }
        }

        char play;
        gotoxy(28, 21);
        cout << "Do You Want To Play Again (Y/N) : ";
        cin >> play;

        if (tolower(play) == 'y') {
            drawBoard();
            char num = '1';
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    space[i][j] = num++;
            token = 'x';
            Tie   = false;
        } else {
            gotoxy(25, 23);
            cout << CYAN << " Thank You For Playing Tic Tac Toe Game!" << endl ;
            break;
        }
    }
}