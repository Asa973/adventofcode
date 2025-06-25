
#include <iostream>
#include <vector>
#include <cmath>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

bool isSafe(const std::vector<int>& levels) {
    if (levels.size() < 2) {
        return true;
    }

    int direction = 0;
    bool valid = true;

    for (size_t i = 1; i < levels.size(); ++i) {
        int diff = levels[i] - levels[i - 1];

        if (diff == 0 || std::abs(diff) > 3) {
            valid = false;
            break;
        }

        if (direction == 0) {
            direction = (diff > 0) ? 1 : -1;
        } else if ((diff > 0 && direction == -1) || (diff < 0 && direction == 1)) {
            valid = false;
            break;
        }
    }

    return valid;
}

bool isSafeWithDampener(const std::vector<int>& levels) {
    if (isSafe(levels)) {
        return true;
    }

    for (size_t i = 0; i < levels.size(); ++i) {
        std::vector<int> modified;

        for (size_t j = 0; j < levels.size(); ++j) {
            if (j != i) {
                modified.push_back(levels[j]);
            }
        }

        if (isSafe(modified)) {
            return true;
        }
    }

    return false;
}

int main()
{
    std::ifstream inputFile("input_level2.txt");
    if (!inputFile) {
        std::cerr << "Error: could not open input_level2.txt" << std::endl;
        return 1;
    }

    std::string line;
    int safeCount = 0;

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::vector<int> levels;
        int num;

        while (iss >> num) {
            levels.push_back(num);
        }

        if (levels.size() < 2) {
            continue;
        }

        if (isSafeWithDampener(levels)) {
            ++safeCount;
        }
    }

    inputFile.close();
    std::cout << "Total: " << safeCount << std::endl;
    return 0;
}
