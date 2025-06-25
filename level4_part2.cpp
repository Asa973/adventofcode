#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/*

*/
bool matchesMASorSAM(char c1, char c2, char c3) {
    return (c1 == 'M' && c2 == 'A' && c3 == 'S') ||
           (c1 == 'S' && c2 == 'A' && c3 == 'M');
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

    // Loop through the grid, skipping edges
    for (int i = 1; i < rows - 1; ++i) {
        for (int j = 1; j < cols - 1; ++j) {
            // Check if center is 'A'
            if (grid[i][j] != 'A') {
                continue;
            }

            // Get diagonal characters
            char topLeft = grid[i - 1][j - 1];
            char bottomRight = grid[i + 1][j + 1];
            char topRight = grid[i - 1][j + 1];
            char bottomLeft = grid[i + 1][j - 1];

            // Check \ diagonal
            bool diag1 = matchesMASorSAM(topLeft, grid[i][j], bottomRight);

            // Check / diagonal
            bool diag2 = matchesMASorSAM(topRight, grid[i][j], bottomLeft);

            if (diag1 && diag2) {
                ++count;
            }
        }
    }

    std::cout << "Total X-MAS patterns: " << count << std::endl;

    return 0;
}
