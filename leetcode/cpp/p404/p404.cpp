// Source: https://leetcode.com/problems/sum-of-left-leaves/
// Date: 25.08.2020
// Solution by: David Luna
// Runtime: 8ms
// Memory usage: 13.7 MB

#include <iostream>
#include <vector>

#include "../lib/treeUtils/treeUtils.h"
#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	int sumOfLeftLeaves(TreeNode *root) {
		int sum;

		sum = 0;
		sumOfLeavesHelper(root, sum);
		return sum;
	}

  private:
	void sumOfLeavesHelper(TreeNode *node, int &sum) {
		if (!node) {
			return;
		}
		if (node->left && !node->left->left && !node->left->right) {
			sum += node->left->val;
		} else {
			sumOfLeavesHelper(node->left, sum);
		}
		sumOfLeavesHelper(node->right, sum);
	}
};

// Leetcode solution ends

void makeTest() {
	std::vector<std::string> treeVect;
	TreeNode *root;
	int ans, correctAns;

	makeVectorT(treeVect);
	std::cin >> correctAns;
	root = makeTree(treeVect);
	ans = Solution().sumOfLeftLeaves(root);
	std::cout << (ans == correctAns ? "pass\n" : "fail\n");
	deleteTree(root);
}

int main() {
	int numTests;
	std::cin >> numTests;
	for (int i = 0; i < numTests; i++) {
		makeTest();
	}
	return 0;
}