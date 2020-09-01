// Source: https://leetcode.com/problems/largest-time-for-given-digits/
// Date: 01.09.2020
// Solution by: David Luna
// Runtime: 0ms
// Memory usage: 9.5 MB

/*
	Note: this solution is based in the one posted in the discuss section of
	the problem.
*/

#include <algorithm>
#include <iostream>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	std::string largestTimeFromDigits(std::vector<int> &A) {
		std::string ans;
		std::sort(A.begin(), A.end());

		ans = "";
		do {
			if ((A[0] * 10 + A[1]) <= maxHours &&
				(A[2] * 10 + A[3]) <= maxMinutes) {
				ans = std::to_string(A[0]) + std::to_string(A[1]) + ':' +
					  std::to_string(A[2]) + std::to_string(A[3]);
			}
		} while (std::next_permutation(A.begin(), A.end()));

		return ans;
	}

  private:
	const uint8_t maxMinutes = 59;
	const uint8_t maxHours = 23;
};

// Leetcode solution ends

std::string formatString(std::string s) {
	if (s.size() <= 2) {
		return "";
	}
	return s.substr(1, s.size() - 2);
}

void makeTest() {
	const int numElements = 4;
	std::vector<int> A;
	std::string ans, correctAns;

	makeVectorT(A, numElements);
	std::cin >> correctAns;
	correctAns = formatString(correctAns);
	ans = Solution().largestTimeFromDigits(A);

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