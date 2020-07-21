// Source: https://leetcode.com/problems/roman-to-integer/
// Date: 26.06.2020
// Solution by: David Luna
// Runtime: 8ms
// Memory usage: 8.2 MB

#include <iostream>

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	int romanToInt(string s) {
		int ans = 0;
		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i] != s[i + 1]) {
				int valueAux = getValue(s[i]);
				if (valueAux < getValue(s[i + 1])) {
					ans -= valueAux;
				} else {
					ans += valueAux;
				}
			} else {
				ans += getValue(s[i]);
			}
		}
		ans += getValue(s[s.size() - 1]);
		return ans;
	}

  private:
	int getValue(char c) {
		switch (c) {
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return 0;
		}
	}
};

// Leetcode solution ends

// Format string from "XXIX" to XXIX.
string formatString(string s) {
	if (s.size() <= 2) {
		return "";
	} else {
		return s.substr(1, s.size() - 2);
	}
}

void makeTest() {
	int correctAns;
	string s;
	// Introduce string with format "XXIX"
	cin >> s >> correctAns;
	s = formatString(s);
	cout << (correctAns == Solution().romanToInt(s) ? "pass\n" : "fail\n");
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