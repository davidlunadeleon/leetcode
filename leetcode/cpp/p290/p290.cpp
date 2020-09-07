// Source: https://leetcode.com/problems/word-pattern/
// Date: 07.09.2020
// Solution by: David Luna
// Runtime: 0ms
// Memory usage: 6.5 MB

#include <iostream>
#include <sstream>
#include <unordered_map>

// Leetcode solution starts

class Solution {
  public:
	bool wordPattern(std::string pattern, std::string str) {
		int i;
		std::string substring;
		std::istringstream stream(str);
		std::unordered_map<std::string, int> wordMap;
		std::unordered_map<char, int> charMap;

		i = 0;
		for (char c : pattern) {
			if (stream.eof()) {
				return false;
			}
			stream >> substring;
			auto itW = wordMap.find(substring);
			auto itC = charMap.find(c);

			if (itW == wordMap.end() && itC == charMap.end()) {
				wordMap.insert(std::make_pair(substring, i));
				charMap.insert(std::make_pair(c, i));
			} else if (itW == wordMap.end() || itC == charMap.end() ||
					   itW->second != itC->second) {
				return false;
			}
			++i;
		}
		if (!stream.eof()) {
			return false;
		}

		return true;
	}
};

// Leetcode solution ends

void makeTest() {
	std::string pattern, str;
	bool ans, correctAns;

	std::cin >> pattern;
	std::cin.ignore();
	std::getline(std::cin, str);
	std::cin >> correctAns;

	ans = Solution().wordPattern(pattern, str);
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
