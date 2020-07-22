// Source: https://leetcode.com/problems/partition-labels/
// Date: 22.07.2020
// Solution by: David Luna
// Runtime: 12ms
// Memory usage: 6.5 MB

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	vector<int> partitionLabels(string S) {
		vector<int> lastPos(26, -1), ans;
		int size = S.size();
		for (int i = 0; i < size; i++) {
			lastPos[S[i] - 'a'] = i;
		}
		for (int i = 0; i < size; i++) {
			int max = lastPos[S[i] - 'a'];
			int j = i;
			for (; j < max; j++) {
				if (lastPos[S[j] - 'a'] > max && j < max) {
					max = lastPos[S[j] - 'a'];
				}
			}
			ans.push_back(max - i + 1);
			i = j;
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
	string s;
	vector<int> ans, correctAns;
	cin >> s;
	makeVectorT(correctAns);
	ans = Solution().partitionLabels(s);
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