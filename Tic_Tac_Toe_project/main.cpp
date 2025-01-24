#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define RESET "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"

using namespace std;

int gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    return 0;
}

void drawBoard();
void takeInput();
bool checkWin();
void playGame();

void Time() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    gotoxy(50, 0);
    cout << "\033[1;36mCurrent date and time : \033[1;37m" << asctime(ltm) << "\033[32m";
}

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, column;
char token = 'x';
bool tie = false;
string name1, name2;

void drawBoard() {
    system("cls");
    gotoxy(34, 0);
    Time();
    gotoxy(30, 2);
    cout << "\033[1;36m====== Tic Tac Toe Game ======\n" << RESET;
    gotoxy(36, 4);
    cout << GREEN << name1 << " : (x) GREEN ";
    gotoxy(36, 6);
    cout << RED << name2 << " : (o) RED " << "\n" << RESET;
    cout << "\033[1;36m\n\t\t\t\t   ___________________\n";
    cout << "\033[1;36m\t\t\t\t   |     |     |     |\n";
    for (int i = 0; i < 3; i++) {
        cout << "\033[1;36m\t\t\t\t   |  ";
        for (int j = 0; j < 3; j++) {
            if (space[i][j] == 'x') {
                cout << GREEN << space[i][j] << "\033[1;36m" ;
            } else if (space[i][j] == 'o') {
                cout << RED << space[i][j] << "\033[1;36m" ;
            } else {
                cout << space[i][j];
            }
            cout << "  |  ";
        }
        cout << "\033[1;36m\n\t\t\t\t   |_____|_____|_____|\n";
        if (i < 2) {
            cout << "\033[1;36m\t\t\t\t   |     |     |     |\n";
        }
    }
    cout << "\n";
}

void takeInput() {
    int digit;
    gotoxy(36, 19);
    if (token == 'o') {
        cout << RED << "\n\t\t\t\t     ==) " << name2 << RESET;
        cout << "\033[1;31m\n\t\t\t\t---------------------\n"
            << "\t\t\t\t Enter your digit : ";
        cin >> digit;
        cout << RESET;
    } else {
        cout << GREEN << "\n\t\t\t\t    ==) " << name1 << RESET;
        cout << "\033[1;32m\n\t\t\t\t---------------------\n"
            << "\t\t\t\t Enter your digit : ";
        cin >> digit;
        cout << RESET;
    }

    switch (digit) {
        case 1: 
            row = 0;
            column = 0;
            break;
        case 2: 
            row = 0;
            column = 1;
            break;
        case 3: 
            row = 0;
            column = 2;
            break;
        case 4: 
            row = 1;
            column = 0;
            break;
        case 5: 
            row = 1;
            column = 1;
            break;
        case 6: 
            row = 1;
            column = 2;
            break;
        case 7: 
            row = 2;
            column = 0;
            break;
        case 8: 
            row = 2;
            column = 1;
            break;
        case 9: 
            row = 2;
            column = 2;
            break;
        default:
            cout << "\n\t\t\t\t Invalid Choice...  !!\n";
            takeInput();
            return;
    }

    if (space[row][column] != 'x' && space[row][column] != 'o') {
        space[row][column] = token;
        token = (token == 'x') ? 'o' : 'x';
    } else {
        cout << "\n\t\t\t    \033[1;31m Position Already Occupied !\033[0m\n";
        takeInput();
    }
}

bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (space[i][0] == space[i][1] && space[i][1] == space[i][2])
            return true;
        if (space[0][i] == space[1][i] && space[1][i] == space[2][i])
            return true;
    }
    // Check diagonals
    if (space[0][0] == space[1][1] && space[1][1] == space[2][2])
        return true;
    if (space[0][2] == space[1][1] && space[1][1] == space[2][0])
        return true;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'x' && space[i][j] != 'o') {
                return false;
            }
        }
    }
    tie = true;
    return true;
}

void playGame() {
    while (true) {
        drawBoard();
        takeInput();
        if (checkWin()) {
            drawBoard();
            if (tie) {
                cout << "\n\t\t\t\t\t\033[1;33mIt's a Tie! \033[0m\n";
            } else if (token == 'o') {
                cout << "\n\t\t\t\t\t" << GREEN << name1 << " WON!" << RESET;
            } else {
                cout << "\n\t\t\t\t\t" << RED << name2 << " WON!" << RESET;
            }
            break;
        }
    }

    char play;
    gotoxy(27,22);
    cout << "Do You Want To Play Again (Y/N) : ";
    cin >> play;
    if (tolower(play) == 'y' || tolower(play) == 'Y'){
        system("cls");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                space[i][j] = '1' + i * 3 + j;
            }
        }
        token = 'x';
        tie = false;
        playGame();
    }
    else {
        gotoxy(24,24);
        cout << "\033[1;36m Thank You For Playing Tic Tac Toe Game\033[0m\n\n";
    }
}

int main() {
    system("cls");
    Time();
    gotoxy(34, 2);
    cout << "\033[1;36m==== Welcome To Tic Tac Toe Game! ====";
    gotoxy(36, 4);
    cout << "\033[1;36m    Enter Player 1 Name : \033[1;37m";
    cin >> name1;
    gotoxy(36, 6);
    cout << "\033[1;36m    Enter Player 2 Name : \033[1;37m";
    cin >> name2;
    cout << RESET;
    playGame();
    return 0;
}
