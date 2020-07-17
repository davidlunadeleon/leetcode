//Source: https://leetcode.com/problems/binary-tree-postorder-traversal/
//Date: 17.07.2020
//Solution by: David Luna
//Runtime: 4ms
//Memory usage: 8.9 MB

#include <iostream>
#include <vector>
#include <stack>

#include "../lib/treeUtils/treeUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
    public:
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> ans;
            if(root != nullptr){
                traversalAux(root, ans);
            }
            return ans;
        }
    private:
        void traversalAux(TreeNode* node, vector<int>& ans){
            if(node->left != nullptr){
                traversalAux(node->left, ans);
            }
            if(node->right != nullptr){
                traversalAux(node->right, ans);
            }
            ans.push_back(node->val);
        }
};

// Leetcode solution ends

template <typename T>
void makeVectorT(vector<T>& vect, int numElements){
    for(int i = 0; i < numElements; i++){
        T temp;
        cin >> temp;
        vect.push_back(temp);
    }
}

void makeTest(){
    int numElementsTree, numElementsAns;
    vector<int> correctAns, ans;
    vector<string> treeVector;
    TreeNode *root;

    cin >> numElementsTree;
    makeVectorT(treeVector, numElementsTree);
    root = makeTree(treeVector);
    
    cin >> numElementsAns;
    makeVectorT(correctAns, numElementsAns);
    
    ans = Solution().postorderTraversal(root);
    
    cout << (ans == correctAns ? "pass\n" : "fail\n");
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