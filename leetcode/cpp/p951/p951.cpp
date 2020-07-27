// Source: https://leetcode.com/problems/flip-equivalent-binary-trees/
// Date: 27.07.2020
// Solution by: David Luna
// Runtime: 4ms
// Memory usage: 12.1 MB

#include <iostream>
#include <vector>

#include "../lib/treeUtils/treeUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	bool flipEquiv(TreeNode *root1, TreeNode *root2) {
		if (!root1 && !root2) {
			return true;
		}
		if ((root1 && !root2) || (root2 && !root1)) {
			return false;
		}
		if (root1->val == root2->val) {
			return (flipEquiv(root1->left, root2->right) &&
					flipEquiv(root1->right, root2->left)) ||
				   (flipEquiv(root1->left, root2->left) &&
					flipEquiv(root1->right, root2->right));
		} else {
			return false;
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
	vector<string> tree1, tree2;
	TreeNode *root1, *root2;
	bool correctAns, ans;
	makeVectorT(tree1);
	makeVectorT(tree2);
	cin >> correctAns;
	root1 = makeTree(tree1);
	root2 = makeTree(tree2);
	ans = Solution().flipEquiv(root1, root2);
	cout << (ans == correctAns ? "pass\n" : "fail\n");
	deleteTree(root1);
	deleteTree(root2);
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