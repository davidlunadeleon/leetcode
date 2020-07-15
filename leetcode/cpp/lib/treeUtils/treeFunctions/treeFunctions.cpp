//Made by David Luna

#include "../treeNode/treeNode.h"
#include <vector>
#include <string>

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

void auxTreeMake(std::vector<std::string> &tree, int index, TreeNode *&node){
    if(index >= tree.size()){
        return;
    }
    if(tree[index] != "null"){
        node = new TreeNode(stoi(tree[index]));
        auxTreeMake(tree, (index * 2) + 1, node->left);
        auxTreeMake(tree, (index * 2) + 2, node->right);
    }
}

TreeNode* makeTree(std::vector<std::string> tree){
    if (tree.empty()) {
        return nullptr;
    }
    TreeNode *root;
    auxTreeMake(tree, 0, root);
    return root;
}

TreeNode* deleteTree(TreeNode*& node){
    if(node->left != nullptr){
       node->left = deleteTree(node->left);
    }
    if(node->right != nullptr){
        node->right = deleteTree(node->right);
    }
    delete node;
    return nullptr;
}