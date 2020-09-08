// Source: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
// Date: 08.09.2020
// Solution by: David Luna
// Runtime: 4ms
// Memory usage: 16.9 MB

#include <iostream>
#include <vector>

#include "../lib/treeUtils/treeUtils.h"
#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	int sumRootToLeaf(TreeNode *root) { return auxSumRootToLeaf(root, 0); }

  private:
	int auxSumRootToLeaf(TreeNode *node, int numSoFar) {
		if (!node) {
			return 0;
		}
		numSoFar = (numSoFar << 1) + node->val;
		if (node->left || node->right) {
			return auxSumRootToLeaf(node->left, numSoFar) +
				   auxSumRootToLeaf(node->right, numSoFar);
		} else {
			return numSoFar;
		}
	}
};

// Leetcode solution ends

void makeTest() {
	std::vector<std::string> tree;
	TreeNode *root;
	int ans, correctAns;

	makeVectorT(tree);
	std::cin >> correctAns;

	root = makeTree(tree);
	ans = Solution().sumRootToLeaf(root);
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
