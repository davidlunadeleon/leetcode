// Source: https://leetcode.com/problems/delete-leaves-with-a-given-value/
// Date: 26.07.2020
// Solution by: David Luna
// Runtime: 12ms
// Memory usage: 18.9 MB

/*
	Note: in the helper function, removeLeafAux, the following if statement is
	present:

		if (node->val == target && node->left == nullptr &&
			node->right == nullptr) {
			return nullptr;
		} ...

	In my opinion, before returning a nullptr if the condition is met, the node
	should be deleted to avoid memory leaks. The problem with that approach is
	that when submitting, a runtime error is reported. This happens with the
	test case tree=[1,1,1] target=1. The error in question is the followign:

	AddressSanitizer: heap-use-after-free on address...

	I still think that having memory leaks is not good, but I could not solve
	the problem without them. My solution would be something like this:

		if (node->val == target && node->left == nullptr &&
			node->right == nullptr) {
			delete node;
			return nullptr;
		} ...
*/

#include <iostream>
#include <vector>

#include "../lib/treeUtils/treeUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	TreeNode *removeLeafNodes(TreeNode *root, int target) {
		root = removeLeafAux(root, target);
		return root;
	}

  private:
	TreeNode *removeLeafAux(TreeNode *node, const int &target) {
		if (!node) {
			return nullptr;
		}
		node->left = removeLeafAux(node->left, target);
		node->right = removeLeafAux(node->right, target);
		if (node->val == target && node->left == nullptr &&
			node->right == nullptr) {
			return nullptr;
		} else {
			return node;
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
	int target;
	TreeNode *ans, *correctAns;
	makeVectorT(tree);
	cin >> target;
	makeVectorT(correctAnsTree);
	ans = makeTree(tree);
	correctAns = makeTree(correctAnsTree);
	ans = Solution().removeLeafNodes(ans, target);
	cout << (compareTrees(ans, correctAns) ? "pass\n" : "fail\n");
	deleteTree(ans);
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