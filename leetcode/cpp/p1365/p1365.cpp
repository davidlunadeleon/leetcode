// Source:
// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
// Date: 04.09.2020
// Solution by: David Luna
// Runtime: 12ms
// Memory usage: 11.1 MB

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	std::vector<int> smallerNumbersThanCurrent(std::vector<int> &nums) {
		uint16_t prevMax, i, counter, size;
		std::multimap<uint8_t, uint16_t> numMap;

		size = nums.size();
		for (i = 0; i < size; ++i) {
			numMap.insert(std::make_pair(nums[i], i));
			nums[i] = 0;
		}

		prevMax = numMap.begin()->first;
		i = counter = 0;
		for (auto it : numMap) {
			if (it.first > prevMax) {
				prevMax = it.first;
				i = counter;
			}
			nums[it.second] = i;
			++counter;
		}

		return nums;
	}
};

// Leetcode solution ends

void makeTest() {
	std::vector<int> nums, ans, correctAns;
	int elements;

	std::cin >> elements;
	makeVectorT(nums, elements);
	makeVectorT(correctAns, elements);
	ans = Solution().smallerNumbersThanCurrent(nums);

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
