//Source: https://leetcode.com/problems/validate-binary-search-tree/
//Date: 02.07.2020
//Solution by: David Luna
//Runtime: 20ms
//Memory usage: 21.8 MB

#include <iostream>
#include <vector>

#include "../lib/treeUtils/treeUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
    public:
        bool isValidBST(TreeNode* root) {
            if(root == nullptr){
                return true;
            }
            bool ans = true;
            int *ptr = nullptr;
            treeTraversal(root, ans, ptr);
            return ans;
        }
    private:
        void treeTraversal(TreeNode* node, bool& flag, int *&previous){
            if(node == nullptr){
                return;
            }
            treeTraversal(node->left, flag, previous);
            if(previous == nullptr){
                previous = &node->val;
            } else if(*previous >= node->val){
                flag = false;
            } else {
                previous = &node->val;
            }
            treeTraversal(node->right, flag, previous);
        }
};

// Leetcode solution ends

void auxTreeMake(vector<string> &tree, int index, TreeNode *&node){
    if(index >= tree.size()){
        return;
    }
    if(tree[index] != "null"){
        node = new TreeNode(stoi(tree[index]));
        auxTreeMake(tree, (index * 2) + 1, node->left);
        auxTreeMake(tree, (index * 2) + 2, node->right);
    }
}

TreeNode* makeTree(vector<string> tree){
    if (tree.empty()) {
        return nullptr;
    }
    TreeNode *root;
    auxTreeMake(tree, 0, root);
    return root;
}

void makeTest(){
    int numNodes;
    bool correctAns;
    TreeNode* treeRoot;
    vector<string> tree;
    cin >> numNodes;
    for(int i = 0; i < numNodes; i++){
        string temp;
        cin >> temp;
        tree.push_back(temp);       
    }
    treeRoot = makeTree(tree);
    cin >> correctAns;
    cout << (correctAns == Solution().isValidBST(treeRoot) ? "pass\n" : "fail\n");
}

int main(){
    int numTests;
    //Introduce the number of tests to make.
    cin >> numTests;
    for(int i = 0; i < numTests; i++){
        makeTest();
    }
    return 0;
}