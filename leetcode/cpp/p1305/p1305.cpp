// Source:
// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
// Date: 05.09.2020
// Solution by: David Luna
// Runtime: 288ms
// Memory usage: 85.1 MB

#include <algorithm>
#include <iostream>
#include <vector>

#include "../lib/treeUtils/treeUtils.h"
#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	std::vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
		std::vector<int> list;
		int middle;

		makeInorderVector(root1, list);
		middle = list.size();
		makeInorderVector(root2, list);
		inplace_merge(list.begin(), list.begin() + middle, list.end());

		return list;
	}

  private:
	void makeInorderVector(TreeNode *node, std::vector<int> &vect) {
		if (node != nullptr) {
			makeInorderVector(node->left, vect);
			vect.push_back(node->val);
			makeInorderVector(node->right, vect);
		}
	}
};

// Leetcode solution ends

void makeTest() {
	std::vector<std::string> tree1, tree2;
	TreeNode *root1, *root2;
	std::vector<int> correctAns, ans;

	makeVectorT(tree1);
	makeVectorT(tree2);
	makeVectorT(correctAns);
	root1 = makeTree(tree1);
	root2 = makeTree(tree2);

	ans = Solution().getAllElements(root1, root2);
	std::cout << (ans == correctAns ? "pass\n" : "fail\n");

	deleteTree(root1);
	deleteTree(root2);
}

int main() {
	int numTests;
	std::cin >> numTests;
	for (int i = 0; i < numTests; i++) {
		makeTest();
	}
	return 0;
}