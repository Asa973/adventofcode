#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>

int main()
{
    std::ifstream inputFile("reports.txt");
    if (!inputFile) {
        std::cerr << "Error could not open reports.txt" << std::endl;
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
            continue; // Can't determine with fewer than 2 levels
        }

        // Determine direction: 1 for increasing, -1 for decreasing, 0 for invalid/mixed
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

        if (valid) {
            ++safeCount;
        }
    }

    inputFile.close();

    std::cout << "Total safe reports: " << safeCount << std::endl;

    return 0;
}

