//Source: https://leetcode.com/problems/maximum-binary-tree/
//Date: 11.07.2020
//Solution by: David Luna
//Runtime: 80ms
//Memory usage: 33 MB

#include <iostream>
#include <vector>
#include <algorithm>

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
        TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
            return constructMaxTreeAux(nums, 0, nums.size() - 1);
        }
    private:
        TreeNode* constructMaxTreeAux(vector<int>& nums, int left, int right){
            if(left > right){
                return nullptr;
            }
            int nodeIndex = max_element(nums.begin() + left, nums.begin() + right + 1) - nums.begin();
            TreeNode* node = new TreeNode(nums[nodeIndex]);
            node->left = constructMaxTreeAux(nums, left, nodeIndex - 1);
            node->right = constructMaxTreeAux(nums, nodeIndex + 1, right);
            return node;
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

vector<int> makeIntVector(int numElements){
    vector<int> ans;
    for(int i = 0; i < numElements; i++){
        int temp;
        cin >> temp;
        ans.push_back(temp);
    }
    return ans;
}

vector<string> makeStringVector(int numElements){
    vector<string> ans;
    for(int i = 0; i < numElements; i++){
        string temp;
        cin >> temp;
        ans.push_back(temp);
    }
    return ans;
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


void makeTest(){
    int numElements, numElementsCorrectAns;
    vector<int> nums;
    vector<string> correctAnsTree; 
    TreeNode *ans, *correctAns;
    cin >> numElements;
    nums = makeIntVector(numElements);
    cin >> numElementsCorrectAns;
    correctAnsTree = makeStringVector(numElementsCorrectAns);
    correctAns = makeTree(correctAnsTree);
    ans = Solution().constructMaximumBinaryTree(nums);
    cout << (compareTrees(ans, correctAns) ? "pass\n" : "fail\n");
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