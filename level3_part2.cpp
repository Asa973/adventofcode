#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>

int parseNumber(const std::string& str, size_t& index) {
    int num = 0;
    while (index < str.size() && std::isdigit(str[index])) {
        num = num * 10 + (str[index] - '0');
        ++index;
    }
    return num;
}

int main() {
    std::ifstream inputFile("input_level3.txt");
    if (!inputFile) {
        std::cerr << "Could not open input_level3.txt" << std::endl;
        return 1;
    }

    std::string line;
    int totalSum = 0;
    bool mulEnabled = true;

    while (std::getline(inputFile, line)) {
        for (size_t i = 0; i < line.size();) {
            if (line.substr(i, 4) == "do()") {
                mulEnabled = true;
                i += 4;
            }
            else if (line.substr(i, 7) == "don't()") {
                mulEnabled = false;
                i += 7;
            }
            else if (line.substr(i, 4) == "mul(") {
                size_t j = i + 4;
                if (j >= line.size() || !std::isdigit(line[j])) {
                    ++i;
                    continue;
                }

                int num1 = parseNumber(line, j);

                if (j >= line.size() || line[j] != ',') {
                    ++i;
                    continue;
                }
                ++j;

                if (j >= line.size() || !std::isdigit(line[j])) {
                    ++i;
                    continue;
                }

                int num2 = parseNumber(line, j);

                if (j >= line.size() || line[j] != ')') {
                    ++i;
                    continue;
                }

                if (mulEnabled) {
                    totalSum += num1 * num2;
                }

                i = j + 1;
            }
            else {
                ++i;
            }
        }
    }

    inputFile.close();

    std::cout << "Total sum of enabled mul() calls: " << totalSum << std::endl;

    return 0;
}
