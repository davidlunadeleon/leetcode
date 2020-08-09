// Source: https://leetcode.com/problems/rotting-oranges/
// Date: 09.08.2020
// Solution by: David Luna
// Runtime: 12ms
// Memory usage: 13 MB

#include <iostream>
#include <queue>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	int orangesRotting(vector<vector<int>> &grid) {
		queue<pair<int, int>> gridQ;
		int numRotten = 0, numOranges = 0, minutes = 0, r, c;
		r = grid.size();
		c = grid[0].size();

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (grid[i][j] != 0) {
					numOranges++;
					if (grid[i][j] == 2) {
						gridQ.push(pair<int, int>(i, j));
						numRotten++;
					}
				}
			}
		}

		while (!gridQ.empty()) {
			int sizeQ = gridQ.size();
			if (numRotten == numOranges) {
				break;
			}
			for (int i = 0; i < sizeQ; i++) {
				pair<int, int> coord = gridQ.front();
				if (coord.first > 0 &&
					grid[coord.first - 1][coord.second] == 1) {
					gridQ.push(pair<int, int>(coord.first - 1, coord.second));
					grid[coord.first - 1][coord.second] = 2;
					numRotten++;
				}
				if (coord.first < r - 1 &&
					grid[coord.first + 1][coord.second] == 1) {
					gridQ.push(pair<int, int>(coord.first + 1, coord.second));
					grid[coord.first + 1][coord.second] = 2;
					numRotten++;
				}
				if (coord.second > 0 &&
					grid[coord.first][coord.second - 1] == 1) {
					gridQ.push(pair<int, int>(coord.first, coord.second - 1));
					grid[coord.first][coord.second - 1] = 2;
					numRotten++;
				}
				if (coord.second < c - 1 &&
					grid[coord.first][coord.second + 1] == 1) {
					gridQ.push(pair<int, int>(coord.first, coord.second + 1));
					grid[coord.first][coord.second + 1] = 2;
					numRotten++;
				}
				gridQ.pop();
			}
			minutes++;
		}

		return numRotten == numOranges ? minutes : -1;
	}
};

// Leetcode solution ends

void makeTest() {
	vector<vector<int>> grid;
	int r, c, ans, correctAns;
	cin >> r >> c;
	makeMatrixT(grid, r, c);
	cin >> correctAns;
	ans = Solution().orangesRotting(grid);
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