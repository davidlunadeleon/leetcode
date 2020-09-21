// Source: https://leetcode.com/problems/car-pooling/
// Date: 21.09.2020
// Solution by: David Luna
// Runtime: 28ms
// Memory usage: 9.9 MB

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	bool carPooling(std::vector<std::vector<int>> &trips, int capacity) {
		int passengers;
		std::multimap<int, int> tripMap;

		std::sort(trips.begin(), trips.end(), [](auto &trip1, auto &trip2) {
			if (trip1.at(1) == trip2.at(1)) {
				return trip1.back() < trip2.back();
			}
			return trip1.at(1) < trip2.at(1);
		});

		passengers = 0;
		for (auto &trip : trips) {
			auto it = tripMap.begin();
			for (; it != tripMap.end() && it->first <= trip.at(1); ++it) {
				passengers -= it->second;
			}
			tripMap.erase(tripMap.begin(), it);

			passengers += trip.front();
			tripMap.insert(std::make_pair(trip.back(), trip.front()));

			if (passengers > capacity) {
				return false;
			}
		}

		return true;
	}
};

// Leetcode solution ends

void makeTest() {
	int capacity;
	bool ans, correctAns;
	std::vector<std::vector<int>> trips;

	makeMatrixT(trips);
	std::cin >> capacity >> correctAns;

	ans = Solution().carPooling(trips, capacity);
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
