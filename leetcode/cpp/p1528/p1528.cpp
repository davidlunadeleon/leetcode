// Source: https://leetcode.com/problems/shuffle-string/
// Date: 31.07.2020
// Solution by: David Luna
// Runtime: 16ms
// Memory usage: 15.3 MB

#include <iostream>
#include <vector>

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	string restoreString(string s, vector<int> &indices) {
		int size = s.size();
		string ans(size, ' ');
		for (int i = 0; i < size; i++) {
			ans[indices[i]] = s[i];
		}
		return ans;
	}
};

// Leetcode solution ends

template <typename T> void makeVectorT(vector<T> &vect) {
	int numElements;
	cin >> numElements;
	for (int i = 0; i < numElements; i++) {
		T temp;
		cin >> temp;
		vect.push_back(temp);
	}
}

void makeTest() {
	string s, ans, correctAns;
	vector<int> indices;
	cin >> s;
	makeVectorT(indices);
	cin >> correctAns;
	ans = Solution().restoreString(s, indices);
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