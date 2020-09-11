// Source: https://leetcode.com/problems/maximum-product-subarray/
// Date: 11.09.2020
// Solution by: David Luna
// Runtime: 8ms
// Memory usage: 12.1 MB

/*
	Note: this solution is completely based on the one posted on the discussion
	section of the problem.
	My original approach was much slower. My idea was basically build all
	possible products of the vector going from smaller to bigger, comparing if
	the current product is bigger than the max stored until this point.
	The code is the following:

	...
	std::vector<int> results = nums;
	size = nums.size();
	ans = *std::max_element(nums.begin(), nums.end());
	step = 1;
	while (step < size) {
		for (i = 0; i + step < size; ++i) {
			if ((results.at(i) *= nums.at(i + step)) > ans) {
				ans = results.at(i);
			}
		}
		++step;
	}
	...
*/

#include <algorithm>
#include <iostream>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	int maxProduct(std::vector<int> &nums) {
		int ans, max, min;

		ans = nums.front();
		max = min = 1;
		for (int i : nums) {
			if (i < 0) {
				std::swap(max, min);
			}
			max = std::max(i, (max * i));
			min = std::min(i, (min * i));
			ans = std::max(ans, max);
		}

		return ans;
	}
};

// Leetcode solution ends

void makeTest() {
	int ans, correctAns;
	std::vector<int> nums;

	makeVectorT(nums);
	std::cin >> correctAns;

	ans = Solution().maxProduct(nums);
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
