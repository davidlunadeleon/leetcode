// Source: https://leetcode.com/problems/reveal-cards-in-increasing-order/
// Date: 16.08.2020
// Solution by: David Luna
// Runtime: 8ms
// Memory usage: 8.3 MB

#include <algorithm>
#include <iostream>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	vector<int> deckRevealedIncreasing(vector<int> &deck) {
		if (deck.empty()) {
			return deck;
		}

		vector<int> ans;
		vector<int>::iterator it;

		sort(deck.begin(), deck.end());
		ans.assign(deck.size(), 0);
		ans[0] = deck[0];
		deck.erase(deck.begin());
		it = ans.begin();
		for (int i : deck) {
			for (int j = 0; j < 2; j++) {
				auto helperIt = find(it + 1, ans.end(), 0);
				it = helperIt;
				if (it == ans.end()) {
					it = find(ans.begin(), ans.end(), 0);
				}
			}
			*it = i;
		}

		return ans;
	}
};

// Leetcode solution ends

void makeTest() {
	int size;
	vector<int> ans, correctAns, deck;

	cin >> size;
	makeVectorT(deck, size);
	makeVectorT(correctAns, size);
	ans = Solution().deckRevealedIncreasing(deck);
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