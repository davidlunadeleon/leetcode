// Source: https://leetcode.com/problems/excel-sheet-column-number/
// Date: 10.08.2020
// Solution by: David Luna
// Runtime: 0ms
// Memory usage: 6.2 MB

#include <iostream>

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	int titleToNumber(string s) {
		int ans = 0;
		for (char c : s) {
			ans = (ans * 26) + (c - 'A' + 1);
		}
		return ans;
	}
};

// Leetcode solution ends

void makeTest() {
	string s;
	int ans, correctAns;
	cin >> s >> correctAns;
	ans = Solution().titleToNumber(s);
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