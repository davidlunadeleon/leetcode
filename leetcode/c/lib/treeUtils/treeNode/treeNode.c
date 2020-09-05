// Taken from https://www.leetcode.com

#include "treeNode.h"

#include <stddef.h>
#include <stdlib.h>

struct TreeNode *initTreeNode() {
	return initTreeNodeInt(0);
}

struct TreeNode *initTreeNodeInt(int x) {
	return initTreeNodeFull(x, NULL, NULL);
}

struct TreeNode *initTreeNodeFull(int x, struct TreeNode *left,
								  struct TreeNode *right) {
	struct TreeNode *ptr = malloc(sizeof(struct TreeNode));
	ptr->val = x;
	ptr->left = left;
	ptr->right = right;

	return ptr;
}

struct TreeNode *deleteTree(struct TreeNode *node) {
	if (!node) {
		return NULL;
	}
	node->left = deleteTree(node->left);
	node->right = deleteTree(node->right);
	free(node);
	return NULL;
}