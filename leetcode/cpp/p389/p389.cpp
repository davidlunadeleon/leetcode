// Source: https://leetcode.com/problems/find-the-difference/
// Date: 24.09.2020
// Solution by: David Luna
// Runtime: 12ms
// Memory usage: 6.7 MB

#include <iostream>

// Leetcode solution starts

class Solution {
  public:
	char findTheDifference(std::string s, std::string t) {
		const int letterInAlphabet = 26;
		int arr[letterInAlphabet]{0};
		int size = s.size();

		for (int i = 0; i < size; ++i) {
			--arr[s.at(i) - 'a'];
			++arr[t.at(i) - 'a'];
		}
		++arr[t.back() - 'a'];

		for (int i = 0; i < letterInAlphabet; ++i) {
			if (arr[i]) {
				return i + 'a';
			}
		}

		return ' ';
	}
};

// Leetcode solution ends

void makeTest() {
	std::string s, t;
	char ans, correctAns;

	std::cin >> s >> t >> correctAns;

	ans = Solution().findTheDifference(s, t);
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
