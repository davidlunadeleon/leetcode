// Taken from https://www.leetcode.com

#pragma once

#ifndef _TREE_NODE
#define _TREE_NODE

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode();
	TreeNode(int x);
	TreeNode(int x, TreeNode *left, TreeNode *right);
};

#endif