// Source: https://leetcode.com/problems/length-of-last-word/
// Date: 15.09.2020
// Solution by: David Luna
// Runtime: 4ms
// Memory usage: 6.5 MB

#include <iostream>
#include <sstream>

// Leetcode solution starts

class Solution {
  public:
	int lengthOfLastWord(std::string s) {
		std::istringstream stream(s);

		s.clear();
		while (!stream.eof()) {
			stream >> s;
		}
		return s.size();
	}
};

// Leetcode solution ends

void makeTest() {
	std::string s;
	int ans, correctAns;

	std::cin >> correctAns;
	std::cin.ignore();
	std::getline(std::cin, s);

	ans = Solution().lengthOfLastWord(s);
	std::cout << ans << ' ' << correctAns << '\n';
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
