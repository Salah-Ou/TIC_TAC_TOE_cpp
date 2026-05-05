#include "utils.h"
#include <iostream>
#include <time.h>
#include <cctype>
#include <string>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

void gotoxy(int x, int y) {
#ifdef _WIN32
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
#else
    cout << "\033[" << y + 1 << ";" << x + 1 << "H";
#endif
}

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void sleep_seconds(int seconds) {
#ifdef _WIN32
    Sleep(seconds * 1000);
#else
    sleep(seconds);  
#endif
}

void Time() {
    clear_screen();
    time_t now = time(0);
    tm* ltm = localtime(&now);
    gotoxy(50, 0);
    cout << GRAY << "Current time : \033[1;37m" << asctime(ltm) << "\033[32m";
}