// Source: https://leetcode.com/problems/valid-palindrome/
// Date: 03.08.2020
// Solution by: David Luna
// Runtime: 12ms
// Memory usage: 7.3 MB

#include <iostream>
#include <string>

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	bool isPalindrome(string s) {
		int i = 0, j = s.size() - 1;
		while (i < j) {
			while (i != j && shouldSkip(s[i])) {
				i++;
			}
			while (i != j && shouldSkip(s[j])) {
				j--;
			}
			if (toupper(s[i]) != toupper(s[j])) {
				return false;
			}
			i++;
			j--;
		}
		return true;
	}

  private:
	bool shouldSkip(const char &c) {
		if ((c >= 48 && c <= 57) || (c >= 65 && c <= 89) ||
			(c >= 97 && c <= 121)) {
			return false;
		}
		return true;
	}
};

// Leetcode solution ends

void makeTest() {
	string inputString;
	bool ans, correctAns;
	cin.ignore();
	getline(cin, inputString);
	cin >> correctAns;
	ans = Solution().isPalindrome(inputString);
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