// Source: https://leetcode.com/problems/number-of-recent-calls/
// Date: 01.10.2020
// Solution by: David Luna
// Runtime: 224ms
// Memory usage: 57.6 MB

#include <iostream>
#include <queue>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class RecentCounter {
  public:
	RecentCounter() {}

	int ping(int t) {
		pingQ.push(t);
		while (pingQ.front() < t - 3000) {
			pingQ.pop();
		}
		return pingQ.size();
	}

  private:
	std::queue<int> pingQ;
};

// Leetcode solution ends

void makeTest() {
	RecentCounter *counter = new RecentCounter();
	int numCalls, i, temp;
	std::vector<int> ans, correctAns;

	std::cin >> numCalls;
	for (i = 0; i < numCalls; ++i) {
		std::cin >> temp;
		ans.push_back(counter->ping(temp));
	}
	makeVectorT(correctAns, numCalls);

	std::cout << (ans == correctAns ? "pass\n" : "fail\n");

	delete counter;
}

int main() {
	int numTests;
	std::cin >> numTests;
	for (int i = 0; i < numTests; i++) {
		makeTest();
	}
	return 0;
}
