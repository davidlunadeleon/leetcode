// Source: https://leetcode.com/problems/h-index/
// Date: 11.08.2020
// Solution by: David Luna
// Runtime: 4ms
// Memory usage: 9.1 MB

/*
	Notes: this solution is completely based in the one posted in the
	discussion section of the problem.

	My original approach was similar, but using a map with iterators
	in the final loop of the problem. The main problem of this approach
	was correctly iterating through the map and doing the condition to
	return the correct h index.
*/

#include <iostream>
#include <map>
#include <tuple>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	int hIndex(vector<int> &citations) {
		int size = citations.size(), ans = 0;
		vector<int> listCitations(size + 1, 0);
		for (int i : citations) {
			int num = i > size ? size : i;
			listCitations[num]++;
		}
		for (; size >= 0; size--) {
			ans += listCitations[size];
			if (ans >= size) {
				return size;
			}
		}
		return 0;
	}
};

// Leetcode solution ends

void makeTest() {
	vector<int> citations;
	int ans, correctAns;
	makeVectorT(citations);
	cin >> correctAns;
	ans = Solution().hIndex(citations);
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
