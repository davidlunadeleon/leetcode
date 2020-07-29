// Source: https://leetcode.com/problems/insert-into-a-binary-search-tree/
// Date: 29.07.2020
// Solution by: David Luna
// Runtime: 152ms
// Memory usage: 38.6 MB

#include <iostream>
#include <vector>

#include "../lib/treeUtils/treeUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	TreeNode *insertIntoBST(TreeNode *root, int val) {
		if (!root) {
			return new TreeNode(val);
		}
		TreeNode *node = root;
		while (node) {
			if (node->val < val) {
				if (node->right) {
					node = node->right;
				} else {
					node->right = new TreeNode(val);
					break;
				}
			} else {
				if (node->left) {
					node = node->left;
				} else {
					node->left = new TreeNode(val);
					break;
				}
			}
		}
		return root;
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
	vector<string> tree;
	vector<TreeNode *> possibleAns;
	int val, numAnswers;
	TreeNode *ans;
	bool checkAns = false;
	makeVectorT(tree);
	cin >> val;
	cin >> numAnswers;
	for (int i = 0; i < numAnswers; i++) {
		vector<string> temp;
		TreeNode *tempRoot;
		makeVectorT(temp);
		tempRoot = makeTree(temp);
		possibleAns.push_back(tempRoot);
	}
	ans = makeTree(tree);
	ans = Solution().insertIntoBST(ans, val);
	for (int i = 0; i < numAnswers; i++) {
		bool check = compareTrees(ans, possibleAns[i]);
		checkAns = checkAns || check;
		possibleAns[i] = deleteTree(possibleAns[i]);
	}
	cout << (checkAns ? "pass\n" : "fail\n");
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