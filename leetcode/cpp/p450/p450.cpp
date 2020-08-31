
// Source: https://leetcode.com/problems/delete-node-in-a-bst/
// Date: 31.08.2020
// Solution by: David Luna
// Runtime: 76ms
// Memory usage: 15.5 MB

#include <iostream>
#include <vector>

#include "../lib/treeUtils/treeUtils.h"
#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	TreeNode *deleteNode(TreeNode *root, int key) {
		root = deleteHelper(root, key);
		return root;
	}

  private:
	TreeNode *deleteHelper(TreeNode *node, const int &key) {
		if (!node) {
			return nullptr;
		}
		if (node->val > key) {
			node->left = deleteHelper(node->left, key);
		} else if (node->val < key) {
			node->right = deleteHelper(node->right, key);
		} else {
			if (!(node->left || node->right)) {
				delete node;
				return nullptr;
			} else if ((node->right && !node->left) ||
					   (!node->right && node->left)) {
				TreeNode *temp = (node->right) ? node->right : node->left;
				delete node;
				return temp;
			} else {
				int newValue = 0;
				TreeNode *curr = node->right;
				while (curr->left) {
					curr = curr->left;
				}
				newValue = curr->val;
				deleteHelper(node, newValue);
				node->val = newValue;
			}
		}
		return node;
	}
};

// Leetcode solution ends

void makeTest() {
	std::vector<std::string> tree, ansTree;
	TreeNode *ans, *correctAns;
	int key;

	makeVectorT(tree);
	std::cin >> key;
	makeVectorT(ansTree);
	ans = makeTree(tree);
	correctAns = makeTree(ansTree);

	ans = Solution().deleteNode(ans, key);
	std::cout << (compareTrees(ans, correctAns) ? "pass\n" : "fail\n");

	deleteTree(ans);
	deleteTree(correctAns);
}

int main() {
	int numTests;
	std::cin >> numTests;
	for (int i = 0; i < numTests; i++) {
		makeTest();
	}
	return 0;
}