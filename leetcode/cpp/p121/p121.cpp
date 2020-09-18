// Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Date: 18.09.2020
// Solution by: David Luna
// Runtime: 8ms
// Memory usage: 13.1 MB

#include <algorithm>
#include <iostream>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	int maxProfit(std::vector<int> &prices) {
		int ans = 0;
		int min = INT32_MAX;

		for (int i : prices) {
			if (i < min) {
				min = i;
			} else {
				ans = std::max(ans, i - min);
			}
		}

		return ans;
	}
};

// Leetcode solution ends

void makeTest() {
	int ans, correctAns;
	std::vector<int> prices;

	makeVectorT(prices);
	std::cin >> correctAns;

	ans = Solution().maxProfit(prices);
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
