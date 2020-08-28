// Source: https://leetcode.com/problems/implement-rand10-using-rand7/
// Date: 28.08.2020
// Solution by: David Luna
// Runtime: 68ms
// Memory usage: 7.4 MB

/*
	Notes:
	- This solution is based on the one presented as the problem solution.

	- The testing of this problem is not enough and only checks if the
	returned number is within the appropiate range.
*/

#include <cstdlib>
#include <iostream>

int rand7() { return ((std::rand() % 7) + 1); }

// Leetcode solution starts

class Solution {
  public:
	int rand10() {
		int temp;

		temp = 40;
		while (temp >= 40) {
			temp = 7 * (rand7() - 1) + (rand7() - 1);
		}
		return ((temp % 10) + 1);
	}
};

// Leetcode solution ends

void makeTest() {
	bool check;
	int times, temp;

	std::cin >> times;
	check = true;
	while (times >= 0) {
		temp = Solution().rand10();
		if (temp > 10 || temp < 1) {
			check = false;
			break;
		}
		--times;
	}
	std::cout << (check ? "pass\n" : "fail\n");
}

int main() {
	int numTests;
	std::cin >> numTests;
	for (int i = 0; i < numTests; i++) {
		makeTest();
	}
	return 0;
}
