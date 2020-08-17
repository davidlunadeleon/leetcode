// Source: https://leetcode.com/problems/distribute-candies-to-people/
// Date: 17.08.2020
// Solution by: David Luna
// Runtime: 0ms
// Memory usage: 6.3 MB

#include <iostream>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	vector<int> distributeCandies(int candies, int num_people) {
		int i, counter;
		vector<int> ans(num_people, 0);

		i = -1;
		counter = 0;
		while (candies > 0) {
			i = (i + 1) % num_people;
			candies -= ++counter;
			ans[i] += counter;
		}
		ans[i] += candies;

		return ans;
	}
};

// Leetcode solution ends

void makeTest() {
	int candies, num_people;
	vector<int> ans, correctAns;

	cin >> candies >> num_people;
	makeVectorT(correctAns);
	ans = Solution().distributeCandies(candies, num_people);
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