// Source: https://leetcode.com/problems/gas-station/
// Date: 23.09.2020
// Solution by: David Luna
// Runtime: 8ms
// Memory usage: 10.1 MB

#include <algorithm>
#include <iostream>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {
		int sum, temp, curr, currVal;
		const int size = gas.size();

		sum = curr = temp = 0;
		for (int i = 0; i < size; ++i) {
			currVal = (gas.at(i) - cost.at(i));
			sum += currVal;
			if ((temp += currVal) < 0) {
				temp = 0;
				curr = i + 1;
			}
		}

		return sum < 0 ? -1 : curr;
	}
};

// Leetcode solution ends

void makeTest() {
	int size, ans, correctAns;
	std::vector<int> gas, cost;

	std::cin >> size;
	makeVectorT(gas, size);
	makeVectorT(cost, size);
	std::cin >> correctAns;

	ans = Solution().canCompleteCircuit(gas, cost);
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
