//Source: https://leetcode.com/problems/range-sum-of-bst/
//Date: 04.07.2020
//Solution by: David Luna
//Runtime: 220ms
//Memory usage: 64.9 MB

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

// Leetcode solution starts

class Solution {
    public:
        int rangeSumBST(TreeNode* root, int L, int R) {
            int ans = 0;
            rangeSum(root, L, R, ans);
            return ans;
        }
    private:
        void rangeSum(TreeNode *node, int &L, int &R, int &ans){
            if(node == nullptr){
                return;
            }
            bool flagR = false, flagL = false;
            if(node->val <= R){
                rangeSum(node->right, L, R, ans);
                flagR = true;
            }
            if(node->val >= L){
                rangeSum(node->left, L, R, ans);
                flagL = true;
            }
            if(flagL && flagR){
                ans+= node->val;
            }
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
    int numNodes, left, right, correctAns;
    TreeNode* treeRoot;
    vector<string> tree;
    cin >> numNodes;
    for(int i = 0; i < numNodes; i++){
        string temp;
        cin >> temp;
        tree.push_back(temp);       
    }
    treeRoot = makeTree(tree);
    cin >> left >> right >> correctAns;
    cout << (correctAns == Solution().rangeSumBST(treeRoot, left, right) ? "pass\n" : "fail\n");
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