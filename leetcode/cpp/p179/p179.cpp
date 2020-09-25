// Source: https://leetcode.com/problems/largest-number/
// Date: 25.09.2020
// Solution by: David Luna
// Runtime:
// Memory usage:

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	std::string largestNumber(std::vector<int> &nums) {
		std::vector<std::string> sVector(nums.size());

		std::transform(nums.begin(), nums.end(), sVector.begin(),
					   [](int x) { return std::to_string(x); });

		std::sort(sVector.begin(), sVector.end(),
				  [](const std::string &a, const std::string &b) {
					  return a + b > b + a;
				  });

		if (sVector.front() == "0") {
			return sVector.front();
		}
		return std::accumulate(std::next(sVector.begin()), sVector.end(),
							   sVector.front(),
							   [](std::string s, const std::string &toAdd) {
								   return std::move(s) + toAdd;
							   });
	}
};

// Leetcode solution ends

void makeTest() {
	std::vector<int> nums;
	std::string ans, correctAns;

	makeVectorT(nums);
	std::cin >> correctAns;

	ans = Solution().largestNumber(nums);
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
