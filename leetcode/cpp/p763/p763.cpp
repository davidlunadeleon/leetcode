// Source: https://leetcode.com/problems/partition-labels/
// Date: 04.09.2020
// Solution by: David Luna
// Runtime: 4ms
// Memory usage: 6.9 MB

#include <algorithm>
#include <iostream>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	std::vector<int> partitionLabels(std::string S) {
		std::vector<int> lastPos(26, -1), ans;
		int size = S.size();
		for (int i = 0; i < size; i++) {
			lastPos[S[i] - 'a'] = i;
		}
		for (int i = 0; i < size; i++) {
			int max, j;

			max = lastPos[S[i] - 'a'];
			for (j = i; j < max; j++) {
				if (lastPos[S[j] - 'a'] > max && j < max) {
					max = lastPos[S[j] - 'a'];
				}
			}
			ans.push_back(max - i + 1);
			i = j;
		}
		return ans;
	}
};

// Leetcode solution ends

void makeTest() {
	std::string s;
	std::vector<int> ans, correctAns;
	std::cin >> s;
	makeVectorT(correctAns);
	ans = Solution().partitionLabels(s);
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