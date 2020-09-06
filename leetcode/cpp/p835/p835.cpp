// Source: https://leetcode.com/problems/image-overlap/
// Date: 06.09.2020
// Solution by: David Luna
// Runtime: 92ms
// Memory usage: 9.2 MB

#include <algorithm>
#include <iostream>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	int largestOverlap(std::vector<std::vector<int>> &A,
					   std::vector<std::vector<int>> &B) {
		if (A.empty()) {
			return 0;
		}

		int i, j, ans;

		this->A = &A;
		this->B = &B;
		ans = 0;
		rc = A.size();
		for (i = -rc + 1; i < rc; ++i) {
			for (j = -rc + 1; j < rc; ++j) {
				ans = std::max(ans, countOverlapping(i, j));
			}
		}
		this->A = nullptr;
		this->B = nullptr;

		return ans;
	}

  private:
	int rc;
	std::vector<std::vector<int>> *A, *B;

	int countOverlapping(int refI, int refJ) {
		int i, j, r, c, overlapping;

		overlapping = 0;
		for (i = 0; i < rc; ++i) {
			for (j = 0; j < rc; ++j) {
				r = refI + i;
				c = refJ + j;
				if (r >= 0 && c >= 0 && r < rc && c < rc) {
					if ((*A)[r][c] && (*B)[i][j]) {
						++overlapping;
					}
				}
			}
		}
		return overlapping;
	}
};

// Leetcode solution ends

void makeTest() {
	int rc, ans, correctAns;
	std::vector<std::vector<int>> A, B;

	std::cin >> rc;
	makeMatrixT(A, rc, rc);
	makeMatrixT(B, rc, rc);
	std::cin >> correctAns;

	ans = Solution().largestOverlap(A, B);
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
