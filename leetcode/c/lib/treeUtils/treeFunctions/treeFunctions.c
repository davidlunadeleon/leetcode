// Made by David Luna

#include "../treeNode/treeNode.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

bool compareTrees(struct TreeNode *ans, struct TreeNode *tree) {
	if (!ans && !tree) {
		return true;
	}
	if ((!ans && tree) || (ans && !tree) || (ans->val != tree->val)) {
		return false;
	}

	bool left, right;

	left = compareTrees(ans->left, tree->left);
	right = compareTrees(ans->right, tree->right);

	return (left && right);
}

void auxMakeTree(char **tree, int size, int index, struct TreeNode *node) {
	if (index >= size) {
		return;
	}
	if (!strcmp(tree[index], "null")) {
		node = initTreeNodeInt(atoi(tree[index]));
		auxMakeTree(tree, size, (index * 2) + 1, node->left);
		auxMakeTree(tree, size, (index * 2) + 2, node->right);
	}
}

struct TreeNode *makeTree(char **tree, int size) {
	if (!size) {
		return NULL;
	}

	struct TreeNode *root = NULL;
	auxMakeTree(tree, size, 0, root);

	return root;
}