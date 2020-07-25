// Source: https://leetcode.com/problems/binary-tree-pruning/
// Date: 25.07.2020
// Solution by: David Luna
// Runtime: 4ms
// Memory usage: 8.6 MB

#include <iostream>
#include <vector>

#include "../lib/treeUtils/treeUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	TreeNode *pruneTree(TreeNode *root) {
		pruneTreeAux(root);
		return root;
	}

  private:
	TreeNode *pruneTreeAux(TreeNode *node) {
		if (node != nullptr) {
			if (node->left != nullptr) {
				node->left = pruneTreeAux(node->left);
			}
			if (node->right != nullptr) {
				node->right = pruneTreeAux(node->right);
			}
			if (node->val == 0 && node->left == nullptr &&
				node->right == nullptr) {
				delete node;
				return nullptr;
			} else {
				return node;
			}
		} else {
			return nullptr;
		}
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
	vector<string> tree, correctAnsTree;
	TreeNode *root, *ans, *correctAns;
	makeVectorT(tree);
	makeVectorT(correctAnsTree);
	root = makeTree(tree);
	correctAns = makeTree(correctAnsTree);
	ans = Solution().pruneTree(root);
	cout << (compareTrees(ans, correctAns) ? "pass\n" : "fail\n");
	deleteTree(root);
	deleteTree(correctAns);
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