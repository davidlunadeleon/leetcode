// Source: https://leetcode.com/problems/design-hashset/
// Date: 02.08.2020
// Solution by: David Luna
// Runtime: 176ms
// Memory usage: 53.6 MB

// Note: this solution is functionally a Binary Search Tree

#include <iostream>
#include <vector>

#include "../lib/treeUtils/treeUtils.h"

using namespace std;

// Leetcode solution starts

class MyHashSet {
  public:
	MyHashSet() { root = nullptr; }
	~MyHashSet() { root = deleteTree(root); }

	void add(int key) {
		if (root) {
			TreeNode *curr = root;
			while (curr) {
				if (curr->val == key) {
					break;
				}
				if (key > curr->val) {
					if (curr->right) {
						curr = curr->right;
					} else {
						curr->right = new TreeNode(key);
						break;
					}
				} else {
					if (curr->left) {
						curr = curr->left;
					} else {
						curr->left = new TreeNode(key);
						break;
					}
				}
			}
		} else {
			root = new TreeNode(key);
		}
	}

	void remove(int key) { root = deleteKey(root, key); }

	bool contains(int key) {
		if (root) {
			TreeNode *curr = root;
			while (curr) {
				if (curr->val == key) {
					return true;
				}
				curr = key > curr->val ? curr->right : curr->left;
			}
		}
		return false;
	}

  private:
	TreeNode *root;

	TreeNode *deleteTree(TreeNode *&node) {
		if (!node) {
			return nullptr;
		}
		node->left = deleteTree(node->left);
		node->right = deleteTree(node->right);
		delete node;
		return nullptr;
	}

	TreeNode *deleteKey(TreeNode *node, const int &key) {
		if (!node) {
			return nullptr;
		} else if (key > node->val) {
			node->right = deleteKey(node->right, key);
		} else if (key < node->val) {
			node->left = deleteKey(node->left, key);
		} else {
			if (!(node->left || node->right)) {
				delete node;
				return nullptr;
			} else if ((node->right && !node->left) ||
					   (!node->right && node->left)) {
				TreeNode *temp = (node->right) ? node->right : node->left;
				delete node;
				return temp;
			} else {
				int newValue = 0;
				TreeNode *curr = node->right;
				while (curr->left) {
					curr = curr->left;
				}
				newValue = curr->val;
				deleteKey(node, newValue);
				node->val = newValue;
			}
		}
		return node;
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
	MyHashSet *obj;
	int numOperations;
	vector<bool> ans, correctAns;
	obj = new MyHashSet();
	cin >> numOperations;
	for (int i = 0; i < numOperations; i++) {
		char operation;
		cin >> operation;
		switch (operation) {
		case 'a':
			int newNum;
			cin >> newNum;
			obj->add(newNum);
			break;
		case 'c':
			bool check;
			int toContain;
			cin >> toContain;
			check = obj->contains(toContain);
			ans.push_back(check);
			break;
		case 'r':
			int toRemove;
			cin >> toRemove;
			obj->remove(toRemove);
			break;
		default:
			break;
		}
	}
	makeVectorT(correctAns);
	cout << (ans == correctAns ? "pass\n" : "fail\n");
	delete obj;
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