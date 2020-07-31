// Source: https://leetcode.com/problems/jewels-and-stones/
// Date: 31.07.2020
// Solution by: David Luna
// Runtime: 4ms
// Memory usage: 6.3 MB

#include <iostream>
#include <unordered_set>

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	int numJewelsInStones(string J, string S) {
		unordered_set<char> jewelSet(J.begin(), J.end());
		int contJewels = 0;
		for (char c : S) {
			if (jewelSet.find(c) != jewelSet.end()) {
				contJewels++;
			}
		}
		return contJewels;
	}
};

// Leetcode solution ends

void makeTest() {
	string J, S;
	int ans, correctAns;
	cin >> J >> S >> correctAns;
	ans = Solution().numJewelsInStones(J, S);
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