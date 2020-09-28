// Source: https://leetcode.com/problems/subarray-product-less-than-k/
// Date: 28.09.2020
// Solution by: David Luna
// Runtime: 248ms
// Memory usage: 92.2 MB

/*
	Note: This solution is completely based on  the solution provided by
	Leetcode in the problem.
*/

#include <algorithm>
#include <iostream>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	int numSubarrayProductLessThanK(std::vector<int> &nums, int k) {
		if (k <= 1) {
			return 0;
		}
		int ans, left, right, size;
		long temp;

		size = nums.size();
		ans = left = 0;
		temp = 1;
		for (right = 0; right < size; ++right) {
			temp *= nums.at(right);
			while (temp >= k) {
				temp /= nums.at(left++);
			}
			ans += right - left + 1;
		}

		return ans;
	}
};

// Leetcode solution ends

void makeTest() {
	std::vector<int> nums;
	int k, ans, correctAns;

	makeVectorT(nums);
	std::cin >> k >> correctAns;

	ans = Solution().numSubarrayProductLessThanK(nums, k);
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
