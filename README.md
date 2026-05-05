# 🎮 Tic Tac Toe — C++ Terminal Game

A two-player Tic Tac Toe game that runs in the terminal, featuring colored output, cursor positioning, real-time clock display, and input validation.

---

## 🕹️ Full Gameplay Preview

https://github.com/user-attachments/assets/9876116d-0b23-4151-9eb4-256eac9dc67c

---

## 📁 Project Structure

> ```
> ├── main.cpp       # Entry point — collects player names and launches the game 
> ├── game.h         # Game class declaration and constructor 
> ├── game.cpp       # Game logic — board rendering, input handling, win detection
> ├── utils.h        # ANSI color macros and utility function declarations
> └── utils.cpp      # Utility implementations — gotoxy, clear_screen, Time, sleep_seconds
> ```

---

## ✨ Features

- 🎨 **Colored terminal UI** — Player 1 moves shown in green, Player 2 in red
- 🕐 **Live clock** — Current time displayed at the top of the screen
- ✅ **Input validation** — Rejects invalid digits and already-occupied cells
- 🔁 **Play again** — Option to replay without restarting the program
- 🤝 **Tie detection** — Detects when all cells are filled with no winner
- 💻 **Cross-platform** — Runs on Windows and Linux/macOS

---

## 🕹️ How to Play

1. Run the program and enter both player names when prompted.
2. The board numbers positions **1–9**, left to right, top to bottom:

> ```
>  1 | 2 | 3
> -----------
>  4 | 5 | 6
> -----------
>  7 | 8 | 9
> ```

3. Players alternate entering a number to place their mark.
   - **Player 1** plays as `x`
   - **Player 2** plays as `o`
4. First to align **three in a row** (horizontally, vertically, or diagonally) wins.
5. If all 9 cells are filled with no winner, the game ends in a **tie**.
6. After each game you are asked to play again (`Y/N`).

---

## 🔧 Build Instructions

### Requirements

- A C++17-compatible compiler (`g++`, `clang++`, or MSVC)
- Linux, macOS, or Windows

### Compile

> ```bash
> g++ -std=c++17 -o tictactoe main.cpp game.cpp utils.cpp
> ```

### Run

> ```bash
> ./tictactoe        # Linux / macOS
> tictactoe.exe      # Windows
> ```

---

## 🖥️ Platform Notes

| Feature      | Windows                           | Linux / macOS                |
|:--------------:|:-----------------------------------:|:------------------------------:|
| Screen clear | `system("cls")`                   | `system("clear")`            |
| Cursor move  | `SetConsoleCursorPosition`        | ANSI escape `\033[y;xH`      |
| Sleep        | `Sleep(ms)` via `<windows.h>`     | `sleep(s)` via `<unistd.h>`  |

---

## 📄 License

This project is intended for educational purposes. Feel free to use, modify, and distribute it freely.
