// Source: https://leetcode.com/problems/pascals-triangle-ii/
// Date: 12.08.2020
// Solution by: David Luna
// Runtime: 0ms
// Memory usage: 6.4 MB

#include <algorithm>
#include <iostream>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	vector<int> getRow(int rowIndex) {
		if (rowIndex <= 0) {
			return {1};
		}
		vector<int> row;
		for (int i = 0; i < rowIndex; i++) {
			vector<int> temp{1};
			int size = row.size() - 1;
			for (int j = 0; j < size; j++) {
				temp.push_back(row[j] + row[j + 1]);
			}
			temp.push_back(1);
			swap(temp, row);
		}
		return row;
	}
};

// Leetcode solution ends

void makeTest() {
	int k;
	vector<int> ans, correctAns;
	cin >> k;
	makeVectorT(correctAns);
	ans = Solution().getRow(k);
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