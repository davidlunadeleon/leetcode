// Source:
// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
// Date: 20.07.2020
// Solution by: David Luna
// Runtime: 348ms
// Memory usage: 84.9 MB

#include <algorithm>
#include <iostream>
#include <vector>

#include "../lib/treeUtils/treeUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
		vector<int> list;
		makeInorderVector(root1, list);
		int middle = list.size();
		makeInorderVector(root2, list);
		inplace_merge(list.begin(), list.begin() + middle, list.end());
		return list;
	}

  private:
	void makeInorderVector(TreeNode *node, vector<int> &vect) {
		if (node != nullptr) {
			makeInorderVector(node->left, vect);
			vect.push_back(node->val);
			makeInorderVector(node->right, vect);
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
	vector<int> correctAns, ans;
	makeVectorT(tree1);
	makeVectorT(tree2);
	makeVectorT(correctAns);
	root1 = makeTree(tree1);
	root2 = makeTree(tree2);
	ans = Solution().getAllElements(root1, root2);
	cout << (ans == correctAns ? "pass\n" : "fail\n");
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