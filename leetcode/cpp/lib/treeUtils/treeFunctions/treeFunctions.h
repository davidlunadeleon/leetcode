// Made by David Luna

#pragma once

#ifndef _TREE_FUNCTIONS
#define _TREE_FUNCTIONS

#include "../treeNode/treeNode.h"
#include <string>
#include <vector>

bool compareTrees(TreeNode *ans, TreeNode *tree);
TreeNode *makeTree(std::vector<std::string> tree);
TreeNode *deleteTree(TreeNode *&node);

#endif