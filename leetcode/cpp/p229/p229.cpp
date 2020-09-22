// Source: https://leetcode.com/problems/majority-element-ii/
// Date: 22.09.2020
// Solution by: David Luna
// Runtime: 32ms
// Memory usage: 15.5 MB

/*
	Note: This solution is completely based on the solution to the problem on
	Leetcode. Some changes were made.

	In this implementation, the number that divides n to get the number of
	elements that appear n / x times, can be changed. The constant divideBy can
	be set to any other number to generalize the problem to element that appear
	more then n / x times.
*/

#include <algorithm>
#include <iostream>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	std::vector<int> majorityElement(std::vector<int> &nums) {
		std::vector<int> ans;
		const int divideBy = 3;
		const int numTimes = nums.size() / divideBy;
		const int numElements = divideBy - 1;
		std::vector<std::pair<int, int>> maxNums(numElements,
												 std::make_pair(0, 0));

		for (int i : nums) {
			bool checkMax = false;
			for (auto &maxPair : maxNums) {
				if (i == maxPair.first) {
					++maxPair.second;
					checkMax = true;
					break;
				}
			}

			bool checkZero = false;
			if (!checkMax) {
				for (auto &maxPair : maxNums) {
					if (maxPair.second == 0) {
						maxPair.first = i;
						++maxPair.second;
						checkZero = true;
						break;
					}
				}
			}

			if (!checkMax && !checkZero) {
				for (auto &maxPair : maxNums) {
					--maxPair.second;
				}
			}
		}

		std::for_each(maxNums.begin(), maxNums.end(),
					  [](auto &maxPair) { maxPair.second = 0; });

		for (int i : nums) {
			for (auto &maxPair : maxNums) {
				if (i == maxPair.first) {
					++maxPair.second;
					break;
				}
			}
		}

		std::for_each(maxNums.begin(), maxNums.end(),
					  [&ans, numTimes](auto &maxPair) {
						  if (maxPair.second > numTimes) {
							  ans.push_back(maxPair.first);
						  }
					  });

		return ans;
	}
};

// Leetcode solution ends

void makeTest() {
	std::vector<int> nums, ans, correctAns;

	makeVectorT(nums);
	makeVectorT(correctAns);

	ans = Solution().majorityElement(nums);
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
