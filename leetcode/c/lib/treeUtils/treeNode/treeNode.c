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

void deleteTree(struct TreeNode *node) {
	if (node) {
		deleteTree(node->left);
		deleteTree(node->right);
		free(node);
	}
}