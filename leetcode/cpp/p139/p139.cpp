// Source: https://leetcode.com/problems/word-break/
// Date: 29.09.2020
// Solution by: David Luna
// Runtime: 20ms
// Memory usage: 13.4 MB

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
		int temp, size = s.size();
		std::queue<int> lastI({0});
		std::vector<bool> visited(size, false);
		std::string tempS;

		std::sort(wordDict.begin(), wordDict.end());
		while (!lastI.empty()) {
			if (!visited.at(lastI.front())) {
				visited.at(lastI.front()) = true;
				temp = lastI.front();
				while (temp < size) {
					tempS = s.substr(lastI.front(), (++temp) - lastI.front());
					if (std::binary_search(wordDict.begin(), wordDict.end(),
										   tempS)) {
						if (temp == size) {
							return true;
						}
						lastI.push(temp);
					}
				}
			}
			lastI.pop();
		}

		return false;
	}
};

// Leetcode solution ends

void makeTest() {
	std::string s;
	std::vector<std::string> wordDict;
	bool ans, correctAns;

	std::cin >> s;
	makeVectorT(wordDict);
	std::cin >> correctAns;

	ans = Solution().wordBreak(s, wordDict);
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
