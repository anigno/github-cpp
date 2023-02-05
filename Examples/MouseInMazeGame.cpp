#include <iostream>

const int ROWS = 5;
const int COLS = 5;
const char MAZE[ROWS][COLS] = {
  { '#', '#', '#', '#', '#' },
  { '#', '.', '.', '.', '#' },
  { '#', '.', '#', '.', '#' },
  { '#', '.', '.', '.', '#' },
  { '#', '#', '#', '#', '#' }
};

bool isValidMove(int row, int col) {
  return row >= 0 && row < ROWS && col >= 0 && col < COLS && MAZE[row][col] != '#';
}

int main() {
  int row = 1, col = 1;
  while (true) {
    std::cout << "The mouse is at: (" << row << ", " << col << ")\n";
    std::cout << "Enter your move (u/d/l/r): ";
    char move;
    std::cin >> move;

    int newRow = row, newCol = col;
    switch (move) {
      case 'u':
        newRow--;
        break;
      case 'd':
        newRow++;
        break;
      case 'l':
        newCol--;
        break;
      case 'r':
        newCol++;
        break;
      default:
        std::cout << "Invalid move\n";
        continue;
    }

    if (!isValidMove(newRow, newCol)) {
      std::cout << "Invalid move\n";
    } else {
      row = newRow;
      col = newCol;
    }
  }
  return 0;
}
