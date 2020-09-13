// Source: https://leetcode.com/problems/insert-interval/
// Date: 13.09.2020
// Solution by: David Luna
// Runtime: 52ms
// Memory usage: 17.4 MB

/*
	Note: this solution is completely based on one posted by the user MissMary
	of the top voted C++ solutions in the discuss section of the problem on
	Leetcode.
*/

#include <algorithm>
#include <iostream>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	std::vector<std::vector<int>>
	insert(std::vector<std::vector<int>> &intervals,
		   std::vector<int> &newInterval) {
		auto compare = [](const std::vector<int> a, const std::vector<int> b) {
			return a.back() < b.front();
		};

		auto range = std::equal_range(intervals.begin(), intervals.end(),
									  newInterval, compare);
		if (range.first == range.second) {
			intervals.insert(range.first, newInterval);
		} else {
			range.second--;
			range.second->front() =
				std::min(range.first->front(), newInterval.front());
			range.second->back() =
				std::max(range.second->back(), newInterval.back());
			intervals.erase(range.first, range.second);
		}

		return intervals;
	}
};

// Leetcode solution ends

void makeTest() {
	const int intervalSize = 2; // {x, y} is of size 2
	int numIntervals, numIntervalsAns;
	std::vector<std::vector<int>> intervals, ans, correctAns;
	std::vector<int> newInterval;

	std::cin >> numIntervals;
	if (numIntervals > 0) {
		makeMatrixT(intervals, numIntervals, intervalSize);
	}
	makeVectorT(newInterval, intervalSize);
	std::cin >> numIntervalsAns;
	makeMatrixT(correctAns, numIntervalsAns, intervalSize);

	ans = Solution().insert(intervals, newInterval);
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
