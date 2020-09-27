// Source: https://leetcode.com/problems/evaluate-division/
// Date: 27.09.2020
// Solution by: David Luna
// Runtime: 4ms
// Memory usage: 8.4 MB

/*
	Note: This solution is messy and not really fast or memory efficient.
	It uses the Floyd-Warshall algorithm, and it really doesn't apply to
	this problem. But at least it works.
*/

#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	std::vector<double>
	calcEquation(std::vector<std::vector<std::string>> &equations,
				 std::vector<double> &values,
				 std::vector<std::vector<std::string>> &queries) {
		int size, nextInsert;

		nextInsert = 0;
		size = equations.size();
		initMap(nextInsert, equations);

		matrix = std::vector<std::vector<double>>(
			mapStr.size(),
			std::vector<double>(mapStr.size(),
								std::numeric_limits<double>::max()));
		initMatrix(size, values, equations);

		size = matrix.size();
		for (int k = 0; k < size; ++k) {
			for (int i = 0; i < size; ++i) {
				for (int j = 0; j < size; ++j) {
					if (matrix[i][k] != std::numeric_limits<double>::max() &&
						matrix[k][j] != std::numeric_limits<double>::max()) {
						matrix[i][j] =
							std::min(matrix[i][j], matrix[i][k] * matrix[k][j]);
					}
				}
			}
		}

		std::vector<double> ans;
		for (auto &query : queries) {
			if (mapStr.find(query.front()) != mapStr.end() &&
				mapStr.find(query.back()) != mapStr.end()) {
				double temp =
					matrix[mapStr.at(query.front())][mapStr.at(query.back())];
				if (temp == std::numeric_limits<double>::max()) {
					ans.push_back(-1.0);
				} else {
					ans.push_back(temp);
				}
			} else {
				ans.push_back(-1.0);
			}
		}

		return ans;
	}

  private:
	std::unordered_map<std::string, int> mapStr;
	std::vector<std::vector<double>> matrix;

	void initMatrix(const int size, const std::vector<double> &values,
					const std::vector<std::vector<std::string>> &equations) {
		for (int i = 0; i < size; ++i) {
			int r, c;
			double val;

			r = mapStr.at(equations.at(i).front());
			c = mapStr.at(equations.at(i).back());
			val = values.at(i);

			matrix[r][r] = matrix[c][c] = 1.0;
			matrix[r][c] = val;
			matrix[c][r] = 1.0 / val;
		}
	}

	void initMap(int &nextInsert,
				 const std::vector<std::vector<std::string>> &equations) {
		for (const auto &eq : equations) {
			if (mapStr.find(eq.front()) == mapStr.end()) {
				mapStr.insert(std::make_pair(eq.front(), nextInsert++));
			}
			if (mapStr.find(eq.back()) == mapStr.end()) {
				mapStr.insert(std::make_pair(eq.back(), nextInsert++));
			}
		}
	}
};

// Leetcode solution ends

void makeTest() {
	std::vector<std::vector<std::string>> equations, queries;
	std::vector<double> values, ans, correctAns;
	int numEq, numQueries;

	std::cin >> numEq;
	makeMatrixT(equations, numEq, 2);
	makeVectorT(values, numEq);
	std::cin >> numQueries;
	makeMatrixT(queries, numQueries, 2);
	makeVectorT(correctAns, numQueries);

	ans = Solution().calcEquation(equations, values, queries);
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
