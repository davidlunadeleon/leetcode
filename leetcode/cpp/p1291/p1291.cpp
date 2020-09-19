// Source: https://leetcode.com/problems/sequential-digits/
// Date: 19.09.2020
// Solution by: David Luna
// Runtime: 0ms
// Memory usage: 6.1 MB

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	std::vector<int> sequentialDigits(int low, int high) {
		std::vector<int> ans;
		std::queue<int> numQueue({1, 2, 3, 4, 5, 6, 7, 8});
		int temp;

		while (!numQueue.empty()) {
			temp = numQueue.front();
			if (temp >= low) {
				ans.push_back(temp);
			}
			if (temp % 10 < 9 &&
				(temp = (temp * 10) + (temp % 10) + 1) <= high) {
				numQueue.push(temp);
			}
			numQueue.pop();
		}

		return ans;
	}
};

// Leetcode solution ends

void makeTest() {
	int high, low;
	std::vector<int> ans, correctAns;

	std::cin >> low >> high;
	makeVectorT(correctAns);

	ans = Solution().sequentialDigits(low, high);
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
