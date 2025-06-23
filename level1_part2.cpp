#include <iostream>
#include <fstream>
#include <vector>
#include <map>
/*


Vector, map

for compiling :)
cpp++ -Wall -Werror -Wextra -std=c++98 <file> 
*/
int main()
{
    std::vector<int> leftList;
    std::map<int, int> rightCount;
    int leftNum, rightNum;

    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Error could not open input.txt" << std::endl;
        return 1;
    }

    while (inputFile >> leftNum >> rightNum) {
        leftList.push_back(leftNum);
        rightCount[rightNum]++;
    }

    inputFile.close();

    long long similarityScore = 0;
    for (size_t i = 0; i < leftList.size(); ++i) {
        int num = leftList[i];
        similarityScore += num * rightCount[num];
    }

    std::cout << "Similarity score: " << similarityScore << std::endl;
  
    return 0;
}
