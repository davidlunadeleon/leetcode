// Source:
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Date: 18.06.2020
// Solution by: David Luna
// Runtime: 12ms
// Memory usage: 6.8 MB

#include <iostream>

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	int lengthOfLongestSubstring(string s) {
		int first = 0, last = 0, maxSize = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s.find(s[i], first) < last) {
				first = s.find(s[i], first) + 1;
			}
			last++;
			if ((last - first) > maxSize) {
				maxSize = last - first;
			}
		}
		return maxSize;
	}
};

// Leetcode solution ends

void makeTest() {
	int correctAns;
	string s;
	// Introduce the string to check and then the correct answer
	cin >> s >> correctAns;
	cout << (correctAns == Solution().lengthOfLongestSubstring(s) ? "pass\n"
																  : "fail\n");
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