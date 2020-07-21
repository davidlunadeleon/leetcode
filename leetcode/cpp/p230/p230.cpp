// Source:
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/
// Date: 15.07.2020
// Solution by: David Luna
// Runtime: 28ms
// Memory usage: 24.3 MB

#include <iostream>
#include <vector>

#include "../lib/treeUtils/treeUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	int kthSmallest(TreeNode *root, int k) {
		int visitedNodes = 0, ans = 0;
		kthSmallestAux(root, k, visitedNodes, ans);
		return ans;
	}

  private:
	void kthSmallestAux(TreeNode *node, int k, int &visitedNodes, int &ans) {
		if (node->left != nullptr) {
			kthSmallestAux(node->left, k, visitedNodes, ans);
		}
		if (visitedNodes == k) {
			return;
		}
		visitedNodes++;
		ans = node->val;
		if (node->right != nullptr) {
			kthSmallestAux(node->right, k, visitedNodes, ans);
		}
	}
};

// Leetcode solution ends

vector<string> makeTreeVector(int numElements) {
	vector<string> tree;
	for (int i = 0; i < numElements; i++) {
		string temp;
		cin >> temp;
		tree.push_back(temp);
	}
	return tree;
}

void makeTest() {
	int numElements, correctAns, smallesElement;
	cin >> numElements;
	vector<string> tree = makeTreeVector(numElements);
	TreeNode *root = makeTree(tree);
	cin >> smallesElement >> correctAns;
	cout << (correctAns == Solution().kthSmallest(root, smallesElement)
				 ? "pass\n"
				 : "fail\n");
	root = deleteTree(root);
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