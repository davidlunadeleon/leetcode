// Source:
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Date: 24.07.2020
// Solution by: David Luna
// Runtime: 24ms
// Memory usage: 13.6 MB

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	vector<int> searchRange(vector<int> &nums, int target) {
		vector<int>::iterator first, last;
		first = lower_bound(nums.begin(), nums.end(), target);
		last = lower_bound(nums.begin(), nums.end(), target + 1);
		if (first == nums.end() || *first != target) {
			return {-1, -1};
		} else {
			int iFirst = first - nums.begin();
			int iLast = --last - nums.begin();
			return {iFirst, iLast};
		}
	}
};

// Leetcode solution ends

template <typename T> void makeVectorT(vector<T> &vect) {
	int numElements;
	cin >> numElements;
	for (int i = 0; i < numElements; i++) {
		T temp;
		cin >> temp;
		vect.push_back(temp);
	}
}

void makeTest() {
	vector<int> nums, ans, correctAns;
	int target;
	makeVectorT(nums);
	cin >> target;
	makeVectorT(correctAns);
	ans = Solution().searchRange(nums, target);
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