#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"
#define GRAY    "\033[1;30m"
#define CLEAN_LINE "\033[2K"

void gotoxy(int x, int y);
void clear_screen();
void Time();
void sleep_seconds(int seconds);

#endif // UTILS_H