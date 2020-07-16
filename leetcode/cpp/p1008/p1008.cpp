//Source: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
//Date: 16.07.2020
//Solution by: David Luna
//Runtime: 8ms
//Memory usage: 11 MB

// *Note: solution made with help of the guide posted by user lee215 at:
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/discuss/252232/JavaC%2B%2BPython-O(N)-Solution

#include <iostream>
#include <vector>

#include "../lib/treeUtils/treeUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
    public:
        TreeNode* bstFromPreorder(vector<int>& preorder) {
            int index = 0;
            TreeNode* root = bstFromPreorderAux(preorder, index, INT32_MAX);
            return root;
        }
    private:
        TreeNode* bstFromPreorderAux(vector<int>& preorder, int& index, int upperBound){
            if((uint64_t)index < preorder.size() && preorder[index] <= upperBound){
                TreeNode* node = new TreeNode(preorder[index]);
                index++;
                node->left = bstFromPreorderAux(preorder, index, node->val);
                node->right = bstFromPreorderAux(preorder, index, upperBound);
                return node;
            } else {
                return nullptr;
            }
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
    int numElements, numElementsAns;
    vector<string> treeAns;
    vector<int> preorderVector;
    TreeNode *ans, *correctAns;
    cin >> numElements;
    makeVectorT(preorderVector, numElements);
    cin >> numElementsAns;
    makeVectorT(treeAns, numElementsAns);
    ans = Solution().bstFromPreorder(preorderVector);
    correctAns = makeTree(treeAns);
    cout << (compareTrees(correctAns, ans) ? "pass\n" : "fail\n");
    deleteTree(ans);
    deleteTree(correctAns);
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