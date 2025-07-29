# Tic Tac Toe Game - README

## 📌 Overview
This is a console-based Tic Tac Toe game implemented in C++ with colorful UI elements and real-time clock display. The game supports two players taking turns to mark spaces on a 3x3 grid.

## 🚀 Features
- **Colorful Interface**: Uses ANSI color codes for an enhanced visual experience
- **Real-time Clock**: Displays current date and time at the top of the screen
- **Player Identification**: Clearly shows which player's turn it is with color coding
- **Input Validation**: Prevents invalid moves and occupied space selections
- **Win/Tie Detection**: Automatically detects game outcomes
- **Replay Option**: Allows players to start a new game after completion

## 🕹️ How to Play
1. Enter player names when prompted
2. Players take turns entering numbers (1-9) corresponding to board positions:
   ```
    1 | 2 | 3
   -----------
    4 | 5 | 6
   -----------
    7 | 8 | 9
   ```
3. Player 1 uses 'x' (green) and Player 2 uses 'o' (red)
4. First player to get 3 marks in a row (horizontally, vertically, or diagonally) wins
5. If all spaces are filled without a winner, the game ends in a tie

## 🔎 Technical Details
- **Platform**: Windows (uses Windows.h for console functions)
- **Dependencies**: 
  - windows.h (for console manipulation)
  - iostream (for input/output)
  - conio.h (for console input)
  - time.h (for clock functionality)
- **Color Coding**:
  - Player 1 (x): Green
  - Player 2 (o): Red
  - Board: Cyan
  - Messages: Various colors for different contexts

## 💻 Compilation and Execution
1. Compile with a C++ compiler (tested with g++ on Windows)
   ```
   g++ tictactoe.cpp -o tictactoe
   ```
2. Run the executable
   ```
   ./tictactoe
   ```

## Notes
- The game clears the console screen between moves for a clean interface
- Input validation ensures only numbers 1-9 are accepted
- The game automatically detects when the board is full (tie game)
- Players can choose to play again after each game completes

Enjoy the game!