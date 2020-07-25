// Source: https://leetcode.com/problems/reducing-dishes/
// Date: 25.07.2020
// Solution by: David Luna
// Runtime: 8ms
// Memory usage: 8 MB

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	int maxSatisfaction(vector<int> &satisfaction) {
		sort(satisfaction.begin(), satisfaction.end());
		if (*(--satisfaction.end()) <= 0) {
			return 0;
		}
		int ans = 0, incr = 0, temp = 0, i = satisfaction.size() - 1;
		do {
			ans = temp;
			incr += satisfaction[i];
			temp += incr;
			i--;
		} while (i >= 0 && temp > ans);
		ans = temp > ans ? temp : ans;
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
	vector<int> satisfaction;
	int ans, correctAns;
	makeVectorT(satisfaction);
	cin >> correctAns;
	ans = Solution().maxSatisfaction(satisfaction);
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