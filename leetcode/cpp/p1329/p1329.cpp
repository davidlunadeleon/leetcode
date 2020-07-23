// Source: https://leetcode.com/problems/sort-the-matrix-diagonally/
// Date: 23.07.2020
// Solution by: David Luna
// Runtime: 56ms
// Memory usage: 9.6 MB

/*
	Note: this solution is based in the one posted in the discussion
	section of the problem.
*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
		map<int, priority_queue<int>> diagMap;
		int sizeH = mat[0].size(), sizeV = mat.size();
		for (int i = sizeV - 1; i >= 0; i--) {
			for (int j = sizeH - 1; j >= 0; j--) {
				if (diagMap.find(i - j) == diagMap.end()) {
					diagMap.insert(pair<int, priority_queue<int>>(
						i - j, priority_queue<int>()));
				}
				diagMap[i - j].push(mat[i][j]);
			}
		}
		for (int i = sizeV - 1; i >= 0; i--) {
			for (int j = sizeH - 1; j >= 0; j--) {
				mat[i][j] = diagMap[i - j].top();
				diagMap[i - j].pop();
			}
		}
		return mat;
	}
};

// Leetcode solution ends

template <typename T> void makeMatrix(vector<vector<T>> &matrix) {
	int rows, columns;
	cin >> rows >> columns;
	for (int i = 0; i < rows; i++) {
		vector<T> tempVector;
		for (int j = 0; j < columns; j++) {
			T temp;
			cin >> temp;
			tempVector.push_back(temp);
		}
		matrix.push_back(tempVector);
	}
}

void makeTest() {
	vector<vector<int>> matrix, ans, correctAns;
	makeMatrix(matrix);
	makeMatrix(correctAns);
	ans = Solution().diagonalSort(matrix);
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