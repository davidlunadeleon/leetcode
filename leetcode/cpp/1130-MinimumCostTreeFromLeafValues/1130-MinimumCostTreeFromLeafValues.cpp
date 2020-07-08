//Source: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
//Date: 08.07.2020
//Solution by: David Luna
//Runtime: 0ms
//Memory usage: 8.7 MB

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Leetcode solution starts

class Solution {
    public:
        int mctFromLeafValues(vector<int>& arr) {
            int ans = 0;
            while(arr.size() > 1){
                vector<int>::iterator minElement = min_element(arr.begin(), arr.end());
                int left = INT32_MAX, right = INT32_MAX;
                if(minElement != arr.begin()){
                    left = *(minElement - 1);
                }
                if(minElement + 1 != arr.end()){
                    right = *(minElement + 1);
                }
                ans += *minElement * min(left, right);
                arr.erase(minElement);
            }
            return ans;
        }
};

// Leetcode solution ends

vector<int> makeTreeArr(int numElements){
    vector<int> ans;
    for(int i = 0; i < numElements; i++){
        int temp;
        cin >> temp;
        ans.push_back(temp);
    }
    return ans;
}

void makeTest(){
    vector<int> arr;
    int numElements, correctAns, ans;
    cin >> numElements;
    arr = makeTreeArr(numElements);
    cin >> correctAns;
    ans = Solution().mctFromLeafValues(arr);
    cout << (correctAns == ans ? "pass\n" : "fail\n");
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