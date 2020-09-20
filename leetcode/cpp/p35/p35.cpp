// Source: https://leetcode.com/problems/search-insert-position/
// Date: 20.09.2020
// Solution by: David Luna
// Runtime: 8ms
// Memory usage: 9.9 MB

#include <algorithm>
#include <iostream>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	int searchInsert(std::vector<int> &nums, int target) {
		return std::upper_bound(nums.begin(), nums.end(), target - 1) -
			   nums.begin();
	}
};

// Leetcode solution ends

void makeTest() {
	int target, ans, correctAns;
	std::vector<int> nums;

	makeVectorT(nums);
	std::cin >> target >> correctAns;

	ans = Solution().searchInsert(nums, target);
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
