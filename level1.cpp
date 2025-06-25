#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>

/*
To solve this problem, we see differents principles
Read two lists of integers
Sort both lists
Pair the smallest with the smallest, second-smallest with second-smallest, etc
Compute the absolute differences and sum them

Vector, read a file, ...

for compiling :)
cpp++ -Wall -Werror -Wextra -std=c++98 <file> 
*/

int main()
{
    std::vector<int> leftList;
    std::vector<int> rightList;
    int leftNum, rightNum;

    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Error could not open input.txt" << std::endl;
        return 1;
    }

    while (inputFile >> leftNum >> rightNum) {
        leftList.push_back(leftNum);
        rightList.push_back(rightNum);
    }

    inputFile.close();

    if (leftList.size() != rightList.size()) {
        std::cerr << "Error lists are not of the same size." << std::endl;
        return 1;
    }

    std::sort(leftList.begin(), leftList.end());
    std::sort(rightList.begin(), rightList.end());

    int totalDistance = 0;
    for (size_t i = 0; i < leftList.size(); ++i) {
        totalDistance += std::abs(leftList[i] - rightList[i]);
    }

    std::cout << "Total distance: " << totalDistance << std::endl;

    return 0;
}
