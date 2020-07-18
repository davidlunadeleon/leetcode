//Source: https://leetcode.com/problems/binary-tree-inorder-traversal/
//Date: 18.07.2020
//Solution by: David Luna
//Runtime: 0ms
//Memory usage: 8.6 MB

#include <iostream>
#include <vector>
#include <stack>

#include "../lib/treeUtils/treeUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
	public:
    	vector<int> inorderTraversal(TreeNode* root) {
			stack<TreeNode*> nodeStack;
			vector<int> ans;
			while (!nodeStack.empty() || root != nullptr) {
				if (root != nullptr) {
					nodeStack.push(root);
					root = root->left;
				} else {
					ans.push_back(nodeStack.top()->val);
					root = nodeStack.top()->right;
					nodeStack.pop();
				}
			}
			return ans;
    	}
};

// Leetcode solution ends

template <typename T>
void makeVectorT(vector<T>& vect, int numElements){
	for(int i = 0; i < numElements; i++){
		T temp;
		cin >> temp;
		vect.push_back(temp);
	}
}

void makeTest(){
	int numElements, numElementsAns;
	vector<string> tree;
	vector<int> correctAns, ans;
	TreeNode* root;
	cin >> numElements;
	makeVectorT(tree, numElements);
	root = makeTree(tree);
	cin >> numElementsAns;
	makeVectorT(correctAns, numElementsAns);
	ans = Solution().inorderTraversal(root);
	cout << (ans == correctAns ? "pass\n" : "fail\n");
}

int main(){
	int numTests;
	//Introduce the number of tests to make.
	cin >> numTests;
	for(int i = 0; i < numTests; i++){
		makeTest();
	}
	return 0;
}