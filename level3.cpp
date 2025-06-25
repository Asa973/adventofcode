#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> 
#include <cctype> 
/*
not sur
  */
int main() {
    std::ifstream inputFile("input_level3.txt");
    if (!inputFile) {
        std::cerr << "Error: Could not open memory.txt" << std::endl;
        return 1;
    }

    std::string memory, line;
    while (std::getline(inputFile, line)) {
        memory += line;
    }
    inputFile.close();

    long long totalSum = 0;
    size_t i = 0;

    while (i < memory.size()) {
        if (memory.substr(i, 4) == "mul(") {
            size_t j = i + 4;
            std::string num1 = "", num2 = "";
            while (j < memory.size() && isdigit(memory[j]) && num1.size() < 3) {
                num1 += memory[j];
                ++j;
            }
            if (num1.size() >= 1 && j < memory.size() && memory[j] == ',') {
                ++j;
                while (j < memory.size() && isdigit(memory[j]) && num2.size() < 3) {
                    num2 += memory[j];
                    ++j;
                }
                if (num2.size() >= 1 && j < memory.size() && memory[j] == ')') {
                    // Valid mul(X,Y) found
                    int n1 = std::atoi(num1.c_str());
                    int n2 = std::atoi(num2.c_str());
                    totalSum += n1 * n2;
                    i = j + 1;
                    continue;
                }
            }
        }

        ++i; 
    }

    std::cout << "Total : " << totalSum << std::endl;

    return 0;
}

