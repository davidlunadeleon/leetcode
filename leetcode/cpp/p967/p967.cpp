// Source:
// https://leetcode.com/problems/numbers-with-same-consecutive-differences/
// Date: 18.08.2020
// Solution by: David Luna
// Runtime: 8ms
// Memory usage: 8.3 MB

#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	vector<int> numsSameConsecDiff(int N, int K) {
		if (N == 1) {
			return vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		}
		unordered_set<int> ansSet;
		queue<int> dfsQueue(deque<int>{1, 2, 3, 4, 5, 6, 7, 8, 9});
		int originalLength, newLength, temp;
		pair<int, int> num;

		do {
			num.first = num.second = dfsQueue.front();
			originalLength = num.first == 0 ? 1 : trunc(log10(num.first)) + 1;

			temp = num.first % 10;
			temp -= K;
			num.first = (num.first * 10) + temp;
			newLength = (log10(num.first)) + 1;
			if (temp >= 0 && newLength > originalLength) {
				if (newLength == N) {
					ansSet.insert(num.first);
				} else {
					dfsQueue.push(num.first);
				}
			}

			temp = num.second % 10;
			temp += K;
			num.second = (num.second * 10) + temp;
			newLength = (log10(num.second)) + 1;
			if (temp < 10 && newLength > originalLength) {
				if (newLength == N) {
					ansSet.insert(num.second);
				} else {
					dfsQueue.push(num.second);
				}
			}

			dfsQueue.pop();
		} while (!dfsQueue.empty());

		return vector<int>(ansSet.begin(), ansSet.end());
	}
};

// Leetcode solution ends

void makeTest() {
	int n, k;
	vector<int> ans, correctAns;

	cin >> n >> k;
	makeVectorT(correctAns);
	ans = Solution().numsSameConsecDiff(n, k);
	sort(ans.begin(), ans.end());
	sort(correctAns.begin(), correctAns.end());
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