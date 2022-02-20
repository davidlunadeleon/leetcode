// Source:
// Date:
// Solution by:
// Runtime:
// Memory usage:

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

// Leetcode solution starts

class Solution {
	public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
		std::vector<int> costs = triangle.back();
		for (auto it = std::next(triangle.rbegin());
			 it != triangle.rend();
			 it++) {
			for (int i = 1; i < it->size() + 1; i++) {
				costs.at(i - 1) = std::min(
					it->at(i - 1) + costs.at(i - 1),
					it->at(i - 1) + costs.at(i)
				);
			}
		}
		return costs.front();
    }
};

// Leetcode solution ends

void makeTest() {}

int main() {
	int numTests;
	std::cin >> numTests;
	for (int i = 0; i < numTests; i++) {
		makeTest();
	}
	return 0;
}
