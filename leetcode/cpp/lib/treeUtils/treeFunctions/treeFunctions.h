#pragma once

#ifndef _TREE_FUNCTIONS
#define _TREE_FUNCTIONS

#include "../treeNode/treeNode.h"
#include <vector>
#include <string>

bool compareTrees(TreeNode* ans, TreeNode* tree);
TreeNode* makeTree(std::vector<std::string> tree);

#endif