// Source: https://leetcode.com/problems/contains-duplicate-iii/
// Date: 02.09.2020
// Solution by: David Luna
// Runtime: 28ms
// Memory usage: 11.3 MB

#include <iostream>
#include <map>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	bool containsNearbyAlmostDuplicate(std::vector<int> &nums, int k, int t) {
		if (k == 0) {
			return false;
		}
		int size, i;
		std::multimap<long, int> numMap;

		size = nums.size();
		for (i = 0; i < size; ++i) {
			std::multimap<long, int>::iterator it =
				numMap.lower_bound((long)nums[i] - (long)t);
			if (it != numMap.end()) {
				while (it != numMap.end() &&
					   std::abs((long)it->first - (long)nums[i]) <= t) {
					if (std::abs(i - it->second) <= k) {
						return true;
					}
					++it;
				}
			}
			numMap.insert(std::make_pair(nums[i], i));
		}

		return false;
	}
};

// Leetcode solution ends

void makeTest() {
	std::vector<int> nums;
	bool ans, correctAns;
	int k, t;

	makeVectorT(nums);
	std::cin >> k >> t >> correctAns;
	ans = Solution().containsNearbyAlmostDuplicate(nums, k, t);

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
