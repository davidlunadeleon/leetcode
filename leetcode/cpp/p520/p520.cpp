// Source: https://leetcode.com/problems/detect-capital/
// Date: 01.08.2020
// Solution by: David Luna
// Runtime: 0ms
// Memory usage: 6 MB

#include <iostream>

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	bool detectCapitalUse(string word) {
		bool allCaps = true, allLowerCase = true;
		int size = word.size();
		for (int i = 1; i < size; i++) {
			allCaps = allCaps && word[i] < 'a';
			allLowerCase = allLowerCase && word[i] >= 'a';
			if (!(allLowerCase || allCaps)) {
				return false;
			}
		}
		if (allCaps && word[0] >= 'a' && size > 1) {
			return false;
		}
		return true;
	}
};

// Leetcode solution ends

void makeTest() {
	string word;
	bool ans, correctAns;
	cin >> word >> correctAns;
	ans = Solution().detectCapitalUse(word);
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
