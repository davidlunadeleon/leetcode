// Source: https://leetcode.com/problems/compare-version-numbers/
// Date: 09.09.2020
// Solution by: David Luna
// Runtime: 0ms
// Memory usage: 6.1 MB

#include <iostream>
#include <string>
#include <vector>

// Leetcode solution starts

class Solution {
  public:
	int compareVersion(std::string version1, std::string version2) {
		int index1, index2, size1, size2, temp;

		index1 = index2 = 0;
		size1 = version1.size();
		size2 = version2.size();
		while (index1 < size1 || index2 < size2) {
			temp = getNextNum(index1, version1, size1) -
				   getNextNum(index2, version2, size2);
			if (temp > 0) {
				return 1;
			} else if (temp < 0) {
				return -1;
			}
		}

		return 0;
	}

  private:
	int getNextNum(int &index, std::string &version, int &size) {
		if (index >= size) {
			return 0;
		}

		int startIndex = index;
		while (index < size && version[++index] != '.')
			;

		return std::stoi(version.substr(startIndex, index++ - startIndex));
	}
};

// Leetcode solution ends

void makeTest() {
	int ans, correctAns;
	std::string version1, version2;

	std::cin >> version1 >> version2 >> correctAns;
	ans = Solution().compareVersion(version1, version2);
	std::cout << (ans == correctAns ? "pass\n" : "fail\n");
}

int main() {
	int numTests;
	std::cin >> numTests;
	for (int i = 0; i < numTests; i++) {
		makeTest();
	}
	return 0;
}
