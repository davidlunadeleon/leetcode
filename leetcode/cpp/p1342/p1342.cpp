// Source:
// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
// Date: 31.07.2020
// Solution by: David Luna
// Runtime: 0ms
// Memory usage: 5.8 MB

#include <iostream>

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	int numberOfSteps(int num) {
		int cont = 0;
		while (num > 0) {
			num = num % 2 == 0 ? num / 2 : num - 1;
			cont++;
		}
		return cont;
	}
};

// Leetcode solution ends

void makeTest() {
	int ans, correctAns, num;
	cin >> num >> correctAns;
	ans = Solution().numberOfSteps(num);
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