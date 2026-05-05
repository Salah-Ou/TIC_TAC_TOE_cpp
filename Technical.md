# 📖 Technical Documentation — Tic Tac Toe C++

---

## 🏗️ Architecture Overview

The project is split into three layers:

> ```
> ┌─────────────────────────────────┐
> │           main.cpp              │  ← Entry point / UI setup
> ├─────────────────────────────────┤
> │        game.h / game.cpp        │  ← Core game logic
> ├─────────────────────────────────┤
> │       utils.h / utils.cpp       │  ← Low-level terminal utilities
> └─────────────────────────────────┘
> ```

---

## 🧩 Class: `Game`

Defined in `game.h`, implemented in `game.cpp`.

### Constructor

> ```cpp
> Game(string name1, string name2);
> ```

Initializes the board with digit characters `'1'`–`'9'`, sets the starting token to `'x'`, and stores both player names.

---

### Private Members

| Member | Type | Description |
|:--------:|:------:|:-------------:|
| `space[3][3]` | `char` | The game board. Cells start as `'1'`–`'9'` and are replaced by `'x'` or `'o'` as players move |
| `row`, `column` | `int` | Last computed cell coordinates from player input |
| `token` | `char` | Whose turn it is — `'x'` for Player 1, `'o'` for Player 2 |
| `Tie` | `bool` | Set to `true` when all cells are filled with no winner |
| `name1`, `name2` | `string` | Display names of both players |

---

### Public Methods

#### `void drawBoard()`
Clears the screen, prints the current timestamp, both player names with their color, and renders the 3×3 board using ANSI box-drawing characters. Cells containing `'x'` are printed in green, `'o'` in red, and unplayed digit cells in default color.

#### `void takeInput()`
Prompts the current player to enter a digit (1–9). Validates that:
- The input is a valid integer
- The digit is within the range 1–9
- The chosen cell is not already occupied

Loops until a valid, unoccupied cell is chosen, then writes the current token into `space[row][column]` and switches the token.

#### `bool checkWin()`
Checks all 8 possible winning lines (3 rows, 3 columns, 2 diagonals). A line counts as a win only if all three cells match **and** hold `'x'` or `'o'`. If no winner is found but all cells are filled, sets `Tie = true` and returns `true`. Returns `false` if the game should continue.

#### `void playGame()`
Outer game loop. Calls `drawBoard()` and `takeInput()` alternately until `checkWin()` returns `true`, then announces the result. Asks the player if they want to play again — if yes, resets the board, token, and tie flag.

---

## 🛠️ Utilities

Defined in `utils.h`, implemented in `utils.cpp`.

### ANSI Color Macros

Defined in `utils.h` as preprocessor macros using ANSI escape codes:

| Macro | Color | Used for |
|:-------:|:-------:|:----------:|
| `RESET` | Default | Resetting color after colored output |
| `RED` | Bright red | Player 2 (`o`) and error messages |
| `GREEN` | Bright green | Player 1 (`x`) |
| `CYAN` | Bright cyan | Board borders and UI elements |
| `WHITE` | Bright white | Player name input |
| `GRAY` | Dark gray | Timestamp display |
| `YELLOW` | Yellow | Tie message |
| `CLEAN_LINE` | — | Erases the current terminal line (`\033[2K`) |

---

### Functions

#### `void gotoxy(int x, int y)`
Moves the terminal cursor to column `x`, row `y`.
- **Windows:** uses `SetConsoleCursorPosition` via `GetStdHandle`
- **Linux/macOS:** emits the ANSI escape sequence `\033[y+1;x+1H`

#### `void clear_screen()`
Clears the entire terminal screen.
- **Windows:** `system("cls")`
- **Linux/macOS:** `system("clear")`

#### `void sleep_seconds(int seconds)`
Pauses execution for the given number of seconds.
- **Windows:** calls `Sleep(seconds * 1000)` (milliseconds)
- **Linux/macOS:** calls the system `sleep(seconds)`

> Named `sleep_seconds` (not `sleep`) to avoid a name collision with the POSIX `sleep()` system function.

#### `void Time()`
Clears the screen and prints the current local time at position (50, 0) using `time()`, `localtime()`, and `asctime()` from `<time.h>`.

---

## 🔄 Game Flow

> ```
> main()
>   │
>   ├─ Read name1, name2
>   ├─ Construct Game(name1, name2)
>   └─ game.playGame()
>         │
>         └─ Loop:
>               ├─ drawBoard()
>               ├─ takeInput()
>               ├─ checkWin()?
>               │     ├─ No  → continue loop
>               │     └─ Yes → drawBoard(), show result
>               │
>               └─ Play again (Y/N)?
>                     ├─ Y → reset board, token, Tie → loop
>                     └─ N → print goodbye, exit
> ```

---

## 🎨 Color Scheme Summary

| Element | Color |
|:---------:|:-------:|
| Board borders & UI chrome | Cyan |
| Player 1 name & `x` marks | Green |
| Player 2 name & `o` marks | Red |
| Timestamp | Gray |
| Error / invalid input messages | Red |
| Tie announcement | Yellow |
| Win announcement | Green (P1) / Red (P2) |

---

## ⚙️ Compiler Flags

| Flag | Purpose |
|:------:|:---------:|
| `-std=c++17` | Required for guaranteed aggregate initialization of `space[3][3]` in the class definition |
| `-Wall -Wextra` | Recommended during development to catch all warnings |

---

## 📦 Dependencies

No external libraries. Uses only the C++ standard library and OS headers:

| Header | Used for |
|:--------:|:---------:|
| `<iostream>` | Console I/O |
| `<string>` | `std::string` for player names |
| `<time.h>` | `time()`, `localtime()`, `asctime()` for the clock |
| `<cctype>` | `tolower()` for play-again input |
| `<windows.h>` *(Windows only)* | `SetConsoleCursorPosition`, `Sleep` |
| `<unistd.h>` *(Linux/macOS only)* | `sleep()` |
| `<termios.h>` *(Linux/macOS only)* | Terminal control (included for future extensibility) |

---