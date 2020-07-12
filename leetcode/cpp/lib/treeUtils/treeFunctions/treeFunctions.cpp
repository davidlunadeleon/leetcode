//Made by David Luna

#include "../treeNode/treeNode.h"

bool compareTrees(TreeNode* ans, TreeNode* tree){
    if(ans == nullptr && tree == nullptr){
        return true;
    }
    if(ans == nullptr && tree != nullptr || ans != nullptr && tree == nullptr || ans->val != tree->val){
        return false;
    }
    bool left = compareTrees(ans->left, tree->left);
    bool right = compareTrees(ans->right, tree->right);
    return (left && right);
}