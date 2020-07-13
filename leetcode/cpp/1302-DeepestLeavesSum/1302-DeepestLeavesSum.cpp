//Source: https://leetcode.com/problems/deepest-leaves-sum/
//Date: 13.07.2020
//Solution by: David Luna
//Runtime: 104ms
//Memory usage: 38.3 MB

#include <iostream>
#include <vector>

#include "../lib/treeUtils/treeUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
    public:
        int deepestLeavesSum(TreeNode* root) {
            int ans = 0, maxDepth = -1;
            deepestLeavesSumAux(root, maxDepth, ans, 0);
            return ans;
        }
    private:
        void deepestLeavesSumAux(TreeNode *node, int &maxDepth, int &ans, int depth){
            if(node == nullptr){
                return;
            }
            bool flagLeft = node->left == nullptr, flagRight = node->right == nullptr;
            if(flagRight && flagLeft){
                if(depth == maxDepth){
                    ans += node->val;
                } else if(depth > maxDepth){
                    maxDepth = depth;
                    ans = node->val;
                }
            } else {
                deepestLeavesSumAux(node->left, maxDepth, ans, depth + 1);
                deepestLeavesSumAux(node->right, maxDepth, ans, depth + 1);
            }
        }
};

// Leetcode solution ends

vector<string> makeStringVector(int numElements){
    vector<string> ans;
    for(int i = 0; i < numElements; i++){
        string temp;
        cin >> temp;
        ans.push_back(temp);
    }
    return ans;
}

void makeTest(){
    int numElements, correctAns;
    vector<string> tree;
    TreeNode *root;
    cin >> numElements;
    tree = makeStringVector(numElements);
    root = makeTree(tree);
    cin >> correctAns;
    cout << (correctAns == Solution().deepestLeavesSum(root) ? "pass\n" : "fail\n");
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