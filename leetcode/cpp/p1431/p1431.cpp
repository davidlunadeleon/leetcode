// Source:
// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
// Date: 19.07.2020
// Solution by: David Luna
// Runtime: 4ms
// Memory usage: 9 MB

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
		int maxCandies = *max_element(candies.begin(), candies.end()),
			size = candies.size();
		vector<bool> ans(size, false);
		for (int i = 0; i < size; i++) {
			if (candies[i] + extraCandies >= maxCandies) {
				ans[i] = true;
			}
		}
		return ans;
	}
};

// Leetcode solution ends

template <typename T> void makeVectorT(vector<T> &vect) {
	int numElements;
	cin >> numElements;
	for (int i = 0; i < numElements; i++) {
		T temp;
		cin >> temp;
		vect.push_back(temp);
	}
}

void makeTest() {
	int extraCandies;
	vector<int> candies;
	vector<bool> ans, correctAns;
	cin >> extraCandies;
	makeVectorT(candies);
	makeVectorT(correctAns);
	ans = Solution().kidsWithCandies(candies, extraCandies);
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