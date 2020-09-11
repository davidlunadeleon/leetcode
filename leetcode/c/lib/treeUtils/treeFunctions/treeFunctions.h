// Made by David Luna

#pragma once

#ifndef _TREE_FUNCTIONS
#define _TREE_FUNCTIONS

#include "../treeNode/treeNode.h"

#include <stdbool.h>

bool compareTrees(struct TreeNode *ans, struct TreeNode *tree);
struct TreeNode *makeTree(char **tree, int size);

#endif