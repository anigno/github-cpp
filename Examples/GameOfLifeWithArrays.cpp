#include <iostream>
#include <chrono>
#include <thread>

const int WIDTH = 20;
const int HEIGHT = 20;

int numAliveNeighbors(int grid[HEIGHT][WIDTH], int x, int y) {
  int count = 0;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      int r = x + i;
      int c = y + j;
      if (r >= 0 && r < HEIGHT && c >= 0 && c < WIDTH) {
        count += grid[r][c];
      }
    }
  }
  count -= grid[x][y];
  return count;
}

void printGrid(int grid[HEIGHT][WIDTH]) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (grid[i][j] == 1) {
        std::cout << " * ";
      } else {
        std::cout << " . ";
      }
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

int main() {
  int grid[HEIGHT][WIDTH];
  // Initialize the grid with random alive/dead cells
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      grid[i][j] = std::rand() % 2;
    }
  }

  while (true) {
    printGrid(grid);
    int newGrid[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
        int count = numAliveNeighbors(grid, i, j);
        if (grid[i][j] == 1) {
          if (count < 2 || count > 3) {
            newGrid[i][j] = 0;
          } else {
            newGrid[i][j] = 1;
          }
        } else {
          if (count == 3) {
            newGrid[i][j] = 1;
          } else {
            newGrid[i][j] = 0;
          }
        }
      }
    }
    for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
        grid[i][j] = newGrid[i][j];
      }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }

  return 0;
}
