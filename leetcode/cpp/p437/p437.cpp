// Source: https://leetcode.com/problems/path-sum-iii/
// Date: 08.08.2020
// Solution by: David Luna
// Runtime: 56ms
// Memory usage: 16.1 MB

#include <iostream>
#include <vector>

#include "../lib/treeUtils/treeUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	int pathSum(TreeNode *root, int sum) {
		if (!root) {
			return 0;
		}
		vector<int> pathsSum;
		int ans = 0;
		traverseTree(root, ans, pathsSum, sum);
		return ans;
	}

  private:
	void traverseTree(TreeNode *node, int &ans, vector<int> &pathsSum,
					  const int &sum) {
		pathsSum.push_back(0);
		int size = pathsSum.size();
		for (int i = 0; i < size; i++) {
			pathsSum[i] += node->val;
			if (pathsSum[i] == sum) {
				ans++;
			}
		}
		if (node->left) {
			traverseTree(node->left, ans, pathsSum, sum);
		}
		if (node->right) {
			traverseTree(node->right, ans, pathsSum, sum);
		}
		for (int i = 0; i < size - 1; i++) {
			pathsSum[i] -= node->val;
		}
		pathsSum.pop_back();
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
	vector<string> treeVector;
	TreeNode *root;
	int ans, correctAns, sum;
	makeVectorT(treeVector);
	cin >> sum >> correctAns;
	root = makeTree(treeVector);
	ans = Solution().pathSum(root, sum);
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