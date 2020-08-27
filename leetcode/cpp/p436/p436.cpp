// Source: https://leetcode.com/problems/find-right-interval/
// Date: 27.08.2020
// Solution by: David Luna
// Runtime: 156ms
// Memory usage: 28.5 MB

#include <iostream>
#include <map>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	std::vector<int>
	findRightInterval(std::vector<std::vector<int>> &intervals) {
		std::map<int, int> indexMap;
		std::map<int, int>::iterator it;
		std::vector<int> ans;
		int i, size;

		size = intervals.size();
		for (i = 0; i < size; ++i) {
			indexMap.insert(std::make_pair(intervals[i].front(), i));
		}
		for (i = 0; i < size; ++i) {
			it = indexMap.lower_bound(intervals[i].back());
			if (it == indexMap.end()) {
				ans.push_back(-1);
			} else {
				ans.push_back(it->second);
			}
		}

		return ans;
	}
};

// Leetcode solution ends

void makeTest() {
	int numIntervals, numsPerInterval;
	std::vector<std::vector<int>> intervals;
	std::vector<int> ans, correctAns;

	numsPerInterval = 2;
	std::cin >> numIntervals;
	makeMatrixT(intervals, numIntervals, numsPerInterval);
	makeVectorT(correctAns, numIntervals);
	ans = Solution().findRightInterval(intervals);
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