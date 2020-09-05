// Made by David Luna

#include <stdbool.h>
#include <stddef.h>

#include "../treeNode/treeNode.h"

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