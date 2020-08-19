// Source: https://leetcode.com/problems/goat-latin/
// Date: 19.08.2020
// Solution by: David Luna
// Runtime: 4ms
// Memory usage: 6.5 MB

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	string toGoatLatin(string S) {
		int pointer1, pointer2, size, wordIndex;
		string modifiedWord, finalAns;
		vector<char> vowels{'A', 'E', 'I', 'O', 'U'};

		size = S.size();
		pointer1 = pointer2 = 0;
		wordIndex = 1;
		finalAns = "";
		while (pointer2 < size) {
			pointer2 = S.find(' ', pointer2);
			if (pointer2 == -1) {
				pointer2 = size;
			}
			modifiedWord = S.substr(pointer1, pointer2 - pointer1);
			if (find(vowels.begin(), vowels.end(), toupper(modifiedWord[0])) ==
				vowels.end()) {
				modifiedWord += modifiedWord[0];
				modifiedWord.erase(0, 1);
			}
			finalAns += modifiedWord + "ma";
			finalAns.append(wordIndex, 'a');
			finalAns.push_back(' ');

			pointer1 = ++pointer2;
			++wordIndex;
		}

		finalAns.pop_back();
		return finalAns;
	}
};

// Leetcode solution ends

void makeTest() {
	string s, ans, correctAns;

	getline(cin, s);
	getline(cin, correctAns);
	ans = Solution().toGoatLatin(s);
	cout << (ans == correctAns ? "pass\n" : "fail\n");
}

int main() {
	int numTests;
	// Introduce the number of tests to make.
	cin >> numTests;
	cin.ignore();
	for (int i = 0; i < numTests; i++) {
		makeTest();
	}
	return 0;
}