// Source: https://leetcode.com/problems/shuffle-the-array/
// Date: 19.07.2020
// Solution by: David Luna
// Runtime: 12ms
// Memory usage: 9.6 MB

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	vector<int> shuffle(vector<int> &nums, int n) {
		vector<int> ans(2 * n, 0);
		int it = 0;
		for (int i = 0; i < n; i++) {
			ans[it] = nums[i];
			ans[it + 1] = nums[i + n];
			it += 2;
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
	vector<int> ans, correctAns;
	makeVectorT(ans);
	makeVectorT(correctAns);
	ans = Solution().shuffle(ans, ans.size() / 2);
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