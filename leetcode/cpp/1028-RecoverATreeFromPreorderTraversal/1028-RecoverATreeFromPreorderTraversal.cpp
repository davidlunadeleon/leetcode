// Source: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
// Date: 06.07.2020
// Solution by: David Luna
// Runtime: 76ms
// Memory usage: 8.8 MB

#include <iostream>
#include <vector>

#include "../lib/treeUtils/treeUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	TreeNode *recoverFromPreorder(string S) {
		TreeNode *root;
		makeTreeFromPreorder(root, S, -1);
		return root;
	}

  private:
	void makeTreeFromPreorder(TreeNode *&node, string &S, int depth) {
		pair<int, int> elementDepth = getDepth(S);
		if (elementDepth.first <= depth) {
			return;
		}
		S.erase(0, elementDepth.second);
		pair<int, int> elementNum = getNum(S);
		node = new TreeNode(elementNum.first);
		S.erase(0, elementNum.second);
		makeTreeFromPreorder(node->left, S, depth + 1);
		makeTreeFromPreorder(node->right, S, depth + 1);
	}
	pair<int, int> getNum(string &S) {
		string ans = "";
		int index = 0;
		while (index < S.size() && S[index] != '-') {
			ans += S[index];
			index++;
		}
		return pair<int, int>(stoi(ans), index);
	}
	pair<int, int> getDepth(string &S) {
		int ans = 0;
		int index = 0;
		while (index < S.size() && S[index] == '-') {
			ans++;
			index++;
		}
		return pair<int, int>(ans, index);
	}
};

// Leetcode solution ends

void auxTreeMake(vector<string> &tree, int index, TreeNode *&node) {
	if (index >= tree.size()) {
		return;
	}
	if (tree[index] != "null") {
		node = new TreeNode(stoi(tree[index]));
		auxTreeMake(tree, (index * 2) + 1, node->left);
		auxTreeMake(tree, (index * 2) + 2, node->right);
	}
}

TreeNode *makeTree(vector<string> tree) {
	if (tree.empty()) {
		return nullptr;
	}
	TreeNode *root;
	auxTreeMake(tree, 0, root);
	return root;
}

void makeTest() {
	string treeString;
	int numElements;
	TreeNode *correctAnsRoot, *treeRoot;
	vector<string> ansTree;
	cin >> treeString >> numElements;
	for (int i = 0; i < numElements; i++) {
		string temp;
		cin >> temp;
		ansTree.push_back(temp);
	}
	correctAnsRoot = makeTree(ansTree);
	treeRoot = Solution().recoverFromPreorder(treeString);
	cout << (compareTrees(correctAnsRoot, treeRoot) ? "pass\n" : "fail\n");
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