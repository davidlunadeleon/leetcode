// Source: https://leetcode.com/problems/repeated-substring-pattern/
// Date: 03.09.2020
// Solution by: David Luna
// Runtime: 60ms
// Memory usage: 15.1 MB

#include <iostream>

// Leetcode solution starts

class Solution {
  public:
	bool repeatedSubstringPattern(std::string s) {
		if (s.size() == 1) {
			return false;
		}

		bool ans;
		int sizeSub, tempIt, size;
		std::string substring;

		sizeSub = tempIt = 1;
		size = s.size();
		substring = s.substr(0, 1);
		while (tempIt <= size - 1) {
			if (size % sizeSub == 0 && substring == s.substr(tempIt, sizeSub)) {
				tempIt += sizeSub;
				ans = true;
			} else {
				substring.push_back(s[sizeSub++]);
				tempIt = sizeSub;
				ans = false;
			}
		}

		return ans;
	}
};

// Leetcode solution ends

void makeTest() {
	bool ans, correctAns;
	std::string s;

	std::cin >> s >> correctAns;
	ans = Solution().repeatedSubstringPattern(s);

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