// Source:
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// Date: 07.08.2020
// Solution by: David Luna
// Runtime: 0ms
// Memory usage: 13.1 MB

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#include "../lib/treeUtils/treeUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	vector<vector<int>> verticalTraversal(TreeNode *root) {
		if (!root) {
			return {};
		}
		map<int, vector<pair<int, int>>> lineMap;
		vector<vector<int>> ans;
		traverseTree(lineMap, root, 0, 0);
		for (auto it = lineMap.begin(); it != lineMap.end(); it++) {
			vector<int> temp;
			sort(it->second.begin(), it->second.end(), sortByY);
			for (pair<int, int> element : it->second) {
				temp.push_back(element.first);
			}
			it->second.clear();
			ans.push_back(temp);
		}
		return ans;
	}

  private:
	void traverseTree(map<int, vector<pair<int, int>>> &lineMap, TreeNode *node,
					  int x, int y) {
		if (lineMap.find(x) == lineMap.end()) {
			lineMap.insert(pair<int, vector<pair<int, int>>>(
				x, vector<pair<int, int>>{pair<int, int>(node->val, y)}));
		} else {
			lineMap[x].push_back(pair<int, int>(node->val, y));
		}

		if (node->left) {
			traverseTree(lineMap, node->left, x - 1, y - 1);
		}
		if (node->right) {
			traverseTree(lineMap, node->right, x + 1, y - 1);
		}
	}

	static bool sortByY(pair<int, int> a, pair<int, int> b) {
		return (a.second != b.second ? a.second > b.second : a.first < b.first);
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
	vector<vector<int>> ans, correctAns;
	int numElements;
	TreeNode *tree;
	makeVectorT(treeVector);
	cin >> numElements;
	for (int i = 0; i < numElements; i++) {
		vector<int> temp;
		makeVectorT(temp);
		correctAns.push_back(temp);
	}
	tree = makeTree(treeVector);
	ans = Solution().verticalTraversal(tree);
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