#include <iostream>
#include <tuple>

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

bool solveMaze(int startRow, int startCol, int destinationRow, int destinationCol) {
  int row, col;
  int moveRow[4] = { -1, 0, 1, 0 };
  int moveCol[4] = { 0, 1, 0, -1 };
  int pathIndex = 0;
  std::tuple<int, int, int> path[ROWS * COLS];

  path[pathIndex++] = std::make_tuple(startRow, startCol, 0);

  while (pathIndex > 0) {
    std::tie(row, col, pathIndex) = path[--pathIndex];

    if (row == destinationRow && col == destinationCol) {
      std::cout << "Found solution\n";
      return true;
    }

    for (int i = 0; i < 4; i++) {
      int nextRow = row + moveRow[i];
      int nextCol = col + moveCol[i];

      if (isValidMove(nextRow, nextCol)) {
        path[pathIndex++] = std::make_tuple(nextRow, nextCol, pathIndex);
      }
    }
  }

  std::cout << "No solution found\n";
  return false;
}

int main() {
  solveMaze(0, 0, ROWS - 1, COLS - 1);
  return 0;
}
