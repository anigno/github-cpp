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
  return row >= 0 && row < ROWS && col >= 0 && col < COLS && MAZE[row][col] != '.';
}

bool solveMaze(int row, int col, int destinationRow, int destinationCol) {
  if (row == destinationRow && col == destinationCol) {
    return true;
  }

  if (!isValidMove(row, col)) {
    return false;
  }

  if (solveMaze(row + 1, col, destinationRow, destinationCol)) {
    std::cout << "(" << row << ", " << col << ") -> ";
    return true;
  }
  if (solveMaze(row, col + 1, destinationRow, destinationCol)) {
    std::cout << "(" << row << ", " << col << ") -> ";
    return true;
  }
  if (solveMaze(row - 1, col, destinationRow, destinationCol)) {
    std::cout << "(" << row << ", " << col << ") -> ";
    return true;
  }
  if (solveMaze(row, col - 1, destinationRow, destinationCol)) {
    std::cout << "(" << row << ", " << col << ") -> ";
    return true;
  }

  return false;
}

int main() {
  if (solveMaze(0, 0, ROWS - 1, COLS - 1)) {
    std::cout << "End\n";
  } else {
    std::cout << "No solution found\n";
  }
  return 0;
}
