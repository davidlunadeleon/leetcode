//Source: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
//Date: 07.07.2020
//Solution by: David Luna
//Runtime: 0ms
//Memory usage: 7.5 MB

#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

using namespace std;

// Leetcode solution starts

class Solution {
    public:
        TreeNode* bstToGst(TreeNode* root) {
            int val = 0;
            modifyNode(root, val);
            return root;
        }
    private:
        void modifyNode(TreeNode *node, int &val){
            if(node->right != nullptr){
                modifyNode(node->right, val);
            }
            val += node->val;
            node->val = val;
            if(node->left != nullptr){
                modifyNode(node->left, val);
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

vector<string> makeTreeVector(int numElements){
    vector<string> ans;
    for(int i = 0; i < numElements; i++){
        string temp;
        cin >> temp;
        ans.push_back(temp);
    }
    return ans;
}

void makeTest(){
    int numElements, numElementsAns;
    TreeNode *treeRoot, *ansRoot;
    vector<string> tree, ansTree;
    cin >> numElements;
    tree = makeTreeVector(numElements);
    cin >> numElementsAns;
    ansTree = makeTreeVector(numElementsAns);
    ansRoot = makeTree(ansTree);
    treeRoot = makeTree(tree);
    treeRoot = Solution().bstToGst(treeRoot);
    cout << (compareTrees(ansRoot, treeRoot) ? "pass\n" : "fail\n");
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