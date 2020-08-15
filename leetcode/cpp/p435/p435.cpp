// Source: https://leetcode.com/problems/non-overlapping-intervals/
// Date: 15.08.2020
// Solution by: David Luna
// Runtime: 36ms
// Memory usage: 10.4 MB

/*
	Note: This solution is completely based on the solution presented in the
	discussion section of the problem.
*/

#include <algorithm>
#include <iostream>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	int eraseOverlapIntervals(vector<vector<int>> &intervals) {
		if (intervals.empty()) {
			return 0;
		}

		int endInt, ans, size;

		ans = 0;
		size = intervals.size();
		sort(intervals.begin(), intervals.end(), sortHelper);
		endInt = intervals[0].back();
		for (int i = 1; i < size; i++) {
			if (intervals[i].front() >= endInt) {
				endInt = intervals[i].back();
			} else {
				++ans;
			}
		}

		return ans;
	}

  private:
	static bool sortHelper(vector<int> &a, vector<int> &b) {
		return a.back() < b.back();
	}
};

// Leetcode solution ends

void makeTest() {
	int numIntervals, ans, correctAns;
	vector<vector<int>> intervals;

	cin >> numIntervals;
	makeMatrixT(intervals, numIntervals, 2);
	cin >> correctAns;
	ans = Solution().eraseOverlapIntervals(intervals);
	cout << (ans == correctAns ? "pass\n" : "fail\n");
}

int main() {
	int numTests;
	// Introduce the number of tests to make.
	cin >> numTests;
	for (int i = 0; i < numTests; i++) {
		makeTest();
	}
	return 0;
}