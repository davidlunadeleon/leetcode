// Source: https://leetcode.com/problems/power-of-four/
// Date: 04.08.2020
// Solution by: David Luna
// Runtime: 4ms
// Memory usage: 6.5 MB

/*
	Note: this function could receive two arguments to test if one number is
	the power of other, the 4 in the log function would need to be replaced
	by the second argument.
*/

#include <cmath>
#include <iostream>

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	bool isPowerOfFour(int num) {
		float ans = log(num) / log(4);
		return (num > 0 && ans == trunc(ans)) ? true : false;
	}
};

// Leetcode solution ends

void makeTest() {
	int num;
	bool ans, correctAns;
	cin >> num >> correctAns;
	ans = Solution().isPowerOfFour(num);
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