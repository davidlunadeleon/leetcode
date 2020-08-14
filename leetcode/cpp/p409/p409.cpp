// Source: https://leetcode.com/problems/longest-palindrome/
// Date: 14.08.2020
// Solution by: David Luna
// Runtime: 4ms
// Memory usage: 6.6 MB

#include <iostream>
#include <vector>

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	int longestPalindrome(string s) {
		vector<uint16_t> cVector(256, 0);
		uint16_t ans = 0;
		bool checkOdd = false;

		for (char c : s) {
			cVector[c]++;
		}

		for (uint16_t it : cVector) {
			uint16_t helper;

			helper = it % 2;
			if (helper && !checkOdd) {
				checkOdd = true;
				ans++;
			}
			ans += it - helper;
		}

		return (int)ans;
	}
};

// Leetcode solution ends

void makeTest() {
	string s;
	int ans, correctAns;

	cin >> s >> correctAns;
	ans = Solution().longestPalindrome(s);
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