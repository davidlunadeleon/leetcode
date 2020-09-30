// Source: https://leetcode.com/problems/first-missing-positive/
// Date: 30.09.2020
// Solution by: David Luna
// Runtime: 0ms
// Memory usage: 10 MB

/*
	Note: this solution is completely based on the one posted by user makuiyu
	in Leetcode. My original approach was having an array of booleans to check
	that the numbers were in order and check if one int was missing. This did
	not meet with the problem requirements on Leetcode.
*/

#include <iostream>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	int firstMissingPositive(std::vector<int> &nums) {
		int i, size;

		i = 0;
		size = nums.size();
		while (i < size) {
			if (nums[i] > 0 && nums[i] <= size &&
				nums[nums[i] - 1] != nums[i]) {
				std::swap(nums[nums[i] - 1], nums[i]);
			} else {
				++i;
			}
		}

		for (i = 0; i < size; ++i) {
			if (nums.at(i) != i + 1) {
				return i + 1;
			}
		}
		return size + 1;
	}
};

// Leetcode solution ends

void makeTest() {
	int ans, correctAns;
	std::vector<int> nums;

	makeVectorT(nums);
	std::cin >> correctAns;

	ans = Solution().firstMissingPositive(nums);
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
