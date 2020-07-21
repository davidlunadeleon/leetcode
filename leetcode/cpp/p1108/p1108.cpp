// Source: https://leetcode.com/problems/defanging-an-ip-address/
// Date: 21.07.2020
// Solution by: David Luna
// Runtime: 0ms
// Memory usage: 5.9 MB

#include <iostream>
#include <regex>

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	string defangIPaddr(string address) {
		for (int i = 0; (uint64_t)i < address.size(); i++) {
			if (address[i] == '.') {
				address.replace(i, 1, "[.]");
				i += 2;
			}
		}
		return address;
	}
};

// Leetcode solution ends

void makeTest() {
	string address, ans, correctAns;
	cin >> address >> correctAns;
	ans = Solution().defangIPaddr(address);
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