// Source: https://leetcode.com/problems/sort-array-by-parity/
// Date: 21.08.2020
// Solution by: David Luna
// Runtime: 12ms
// Memory usage: 16.3 MB

#include <algorithm>
#include <iostream>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	vector<int> sortArrayByParity(vector<int> &A) {
		int size, j, i, temp;

		size = A.size();
		for (i = 0, j = size - 1; i <= j; ++i) {
			if (A[i] % 2) {
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
				i--;
				j--;
			}
		}

		return A;
	}
};

// Leetcode solution ends

bool validateAnswer(const vector<int> &V) {
	int i, size;

	i = 0;
	size = V.size();
	while (i < size && V[i] % 2 == 0) {
		i++;
	}
	while (i < size) {
		if (V[i++] % 2 == 0) {
			return false;
		}
	}

	return true;
}

void makeTest() {
	vector<int> ans;

	makeVectorT(ans);
	ans = Solution().sortArrayByParity(ans);
	cout << (validateAnswer(ans) ? "pass\n" : "fail\n");
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