// Made by David Luna

#include "../treeNode/treeNode.h"
#include <string>
#include <vector>

bool compareTrees(TreeNode *ans, TreeNode *tree) {
	if (ans == nullptr && tree == nullptr) {
		return true;
	}
	if ((ans == nullptr && tree != nullptr) ||
		(ans != nullptr && tree == nullptr) || ans->val != tree->val) {
		return false;
	}
	bool left = compareTrees(ans->left, tree->left);
	bool right = compareTrees(ans->right, tree->right);
	return (left && right);
}

void auxTreeMake(std::vector<std::string> &tree, int index, TreeNode *&node) {
	if ((uint64_t)index >= tree.size()) {
		return;
	}
	if (tree[index] != "null") {
		node = new TreeNode(stoi(tree[index]));
		auxTreeMake(tree, (index * 2) + 1, node->left);
		auxTreeMake(tree, (index * 2) + 2, node->right);
	}
}

TreeNode *makeTree(std::vector<std::string> tree) {
	if (tree.empty()) {
		return nullptr;
	}
	TreeNode *root;
	auxTreeMake(tree, 0, root);
	return root;
}

TreeNode *deleteTree(TreeNode *&node) {
	if (!node) {
		return nullptr;
	}
	node->left = deleteTree(node->left);
	node->right = deleteTree(node->right);
	delete node;
	return nullptr;
}