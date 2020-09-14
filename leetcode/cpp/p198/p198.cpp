// Source: https://leetcode.com/problems/house-robber/
// Date: 14.09.2020
// Solution by: David Luna
// Runtime: 4ms
// Memory usage: 7.9 MB

/*
	Note: this solution is completely based on the one posted by user Jasonly
	on Leetcode in the discuss section of this problem.
*/

#include <algorithm>
#include <iostream>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	int rob(std::vector<int> &nums) {
		bool isPair;
		int pair, odd;

		pair = odd = isPair = 0;
		for (int i : nums) {
			if (isPair) {
				pair = std::max(pair + i, odd);
			} else {
				odd = std::max(odd + i, pair);
			}
			isPair = !isPair;
		}
		return std::max(pair, odd);
	}
};

// Leetcode solution ends

void makeTest() {
	int ans, correctAns;
	std::vector<int> nums;

	makeVectorT(nums);
	std::cin >> correctAns;
	ans = Solution().rob(nums);

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
