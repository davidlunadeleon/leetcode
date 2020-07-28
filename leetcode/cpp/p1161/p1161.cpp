// Source: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
// Date: 28.07.2020
// Solution by: David Luna
// Runtime: 356ms
// Memory usage: 107.4 MB

/*
	Notes: The returned level is actually the level + 1, since root is actually
	at level 0, not level 1.

	In my opinion, the function maxLevelSum should have a check at the beginning
	to see if root is not a null pointer. Like this:

	if(!root){
		return 0;
	}

	The problem restrictions state that the number of nodes ranges from 0 to
	10^4, so there is no problem for not checking if the given tree is empty
	or not.
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#include "../lib/treeUtils/treeUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	int maxLevelSum(TreeNode *root) {
		queue<TreeNode *> nodeQ;
		nodeQ.push(root);
		int ans = root->val, ansDepth = 1, depthCheck = 1;
		while (!nodeQ.empty() && root != nullptr) {
			int size = nodeQ.size();
			int ansTemp = 0;
			for (int i = 0; i < size; i++) {
				root = nodeQ.front();
				if (root->left) {
					nodeQ.push(root->left);
				}
				if (root->right) {
					nodeQ.push(root->right);
				}
				ansTemp += root->val;
				nodeQ.pop();
			}
			if (ansTemp > ans) {
				ans = ansTemp;
				ansDepth = depthCheck;
			}
			depthCheck++;
		}
		return ansDepth;
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
	int ans, correctAns;
	TreeNode *root;
	makeVectorT(tree);
	cin >> correctAns;
	root = makeTree(tree);
	ans = Solution().maxLevelSum(root);
	cout << (ans == correctAns ? "pass\n" : "fail\n");
	deleteTree(root);
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