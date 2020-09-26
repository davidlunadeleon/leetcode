// Source: https://leetcode.com/problems/teemo-attacking/
// Date: 26.09.2020
// Solution by: David Luna
// Runtime: 80ms
// Memory usage: 26.2 MB

#include <iostream>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	int findPoisonedDuration(std::vector<int> &timeSeries, int duration) {
		int lastTime, poisonedTime;

		lastTime = poisonedTime = 0;
		for (const int i : timeSeries) {
			poisonedTime += std::min(duration, i + duration - lastTime);
			lastTime = i + duration;
		}

		return poisonedTime;
	}
};

// Leetcode solution ends

void makeTest() {
	int duration, ans, correctAns;
	std::vector<int> timeSeries;

	makeVectorT(timeSeries);
	std::cin >> duration >> correctAns;

	ans = Solution().findPoisonedDuration(timeSeries, duration);
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
