// Taken from https://www.leetcode.com

#pragma once

#ifndef _TREE_NODE
#define _TREE_NODE

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *initTreeNode();
struct TreeNode *initTreeNodeInt(int x);
struct TreeNode *initTreeNodeFull(int x, struct TreeNode *left,
								  struct TreeNode *right);

struct TreeNode *deleteTree(struct TreeNode *node);

#endif