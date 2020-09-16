// Source: https://leetcode.com/problems/third-maximum-number/
// Date: 16.09.2020

// Solution by: David Luna
// Runtime: 12ms
// Memory usage: 10.7 MB

#include <iostream>
#include <set>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	int thirdMax(std::vector<int> &nums) {
		std::set<int> numSet;

		for (int i : nums) {
			numSet.insert(i);
			if (numSet.size() > 3) {
				numSet.erase(numSet.begin());
			}
		}

		return numSet.size() == 3 ? *numSet.begin() : *numSet.rbegin();
	}
};

// Leetcode solution ends

void makeTest() {
	int ans, correctAns;
	std::vector<int> nums;

	makeVectorT(nums);
	std::cin >> correctAns;

	ans = Solution().thirdMax(nums);
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
