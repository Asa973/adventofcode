#include <iostream>
#include <fstream>
#include <string>
#include <vector>


/*
DX[] and DY[] define movement in the 8 directions.

checkDirection() verifies if "XMAS" fits in the chosen direction from (x,y).

The main loop checks every cell and every direction.
*/
const std::string TARGET = "XMAS";
const int DX[] = {0, 0, 1, -1, 1, 1, -1, -1};  // Directions for rows
const int DY[] = {1, -1, 0, 0, 1, -1, 1, -1};  // Directions for columns

bool checkDirection(const std::vector<std::string>& grid, int x, int y, int dir, int rows, int cols) {
    for (int k = 0; k < 4; ++k) {
        int nx = x + k * DX[dir];
        int ny = y + k * DY[dir];

        if (nx < 0 || nx >= rows || ny < 0 || ny >= cols) {
            return false;
        }

        if (grid[nx][ny] != TARGET[k]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ifstream inputFile("input_level4.txt");
    if (!inputFile) {
        std::cerr << "Error: Could not open input_level4.txt" << std::endl;
        return 1;
    }

    std::vector<std::string> grid;
    std::string line;

    while (std::getline(inputFile, line)) {
        if (!line.empty()) {
            grid.push_back(line);
        }
    }
    inputFile.close();

    int rows = grid.size();
    if (rows == 0) {
        std::cout << "Empty grid." << std::endl;
        return 0;
    }
    int cols = grid[0].size();
    int count = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int dir = 0; dir < 8; ++dir) {
                if (checkDirection(grid, i, j, dir, rows, cols)) {
                    ++count;
                }
            }
        }
    }

    std::cout << "Total occurrences of XMAS: " << count << std::endl;

    return 0;
}
