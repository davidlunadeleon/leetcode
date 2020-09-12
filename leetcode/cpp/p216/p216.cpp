// Source: https://leetcode.com/problems/combination-sum-iii/
// Date: 12.09.2020
// Solution by: David Luna
// Runtime: 0ms
// Memory usage: 6.4 MB

#include <algorithm>
#include <iostream>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	std::vector<std::vector<int>> combinationSum3(int k, int n) {
		if (k == 1 && n < 10) {
			return {{n}};
		}
		std::vector<int> temp;

		this->k = k;
		this->n = n;
		for (int i = 1; i < n && i < 10; ++i) {
			arr.push_back(i);
			completeCombination(i, i);
			arr.pop_back();
		}

		return ans;
	}

  private:
	std::vector<std::vector<int>> ans;
	std::vector<int> arr;
	int k, n;

	void completeCombination(int i, int sum) {
		if ((int)arr.size() > k) {
			return;
		}
		if ((int)arr.size() == k && sum == n) {
			ans.push_back(arr);
		} else {
			for (++i; i + sum <= n && i < 10; ++i) {
				arr.push_back(i);
				completeCombination(i, sum + i);
				arr.pop_back();
			}
		}
	}
};

// Leetcode solution ends

template <typename T> void sortMatrix(std::vector<std::vector<T>> &matrix) {
	for (std::vector<T> &row : matrix) {
		std::sort(row.begin(), row.end());
	}
	std::sort(matrix.begin(), matrix.end());
}

void makeTest() {
	std::vector<std::vector<int>> ans, correctAns;
	int k, n;

	std::cin >> k >> n;
	makeMatrixT(correctAns);
	ans = Solution().combinationSum3(k, n);
	sortMatrix(correctAns);
	sortMatrix(ans);

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
