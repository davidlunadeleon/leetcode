// Source: https://leetcode.com/problems/find-all-duplicates-in-an-array/
// Date: 06.08.2020
// Solution by: David Luna
// Runtime: 184ms
// Memory usage: 45.9 MB

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	vector<int> findDuplicates(vector<int> &nums) {
		unordered_set<int> numSet;
		vector<int> ans;
		for (int i : nums) {
			if (numSet.find(i) != numSet.end()) {
				ans.push_back(i);
			} else {
				numSet.insert(i);
			}
		}
		return ans;
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
	makeVectorT(nums);
	makeVectorT(correctAns);
	ans = Solution().findDuplicates(nums);
	sort(ans.begin(), ans.end());
	sort(correctAns.begin(), correctAns.end());
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