//Source: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
//Date: 01.07.2020
//Solution by: David Luna
//Runtime: 0ms
//Memory usage: 6.6 MB

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Leetcode solution starts

class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            vector<string> ans;
            vector<vector<int>> nums{
                vector<int>{' '},
                vector<int>{},
                vector<int>{'a', 'b', 'c'},
                vector<int>{'d', 'e', 'f'},
                vector<int>{'g', 'h', 'i'},
                vector<int>{'j', 'k', 'l'},
                vector<int>{'m', 'n', 'o'},
                vector<int>{'p', 'q', 'r', 's'},
                vector<int>{'t', 'u', 'v'},
                vector<int>{'w', 'x', 'y', 'z'}
            };
            string empty = "";
            makeCombinations(ans, nums, digits, 0, empty);
            if(ans.size() == 1 || digits.size() == 0){
                return vector<string>{};
            }
            return ans;
        }
    private:
        void makeCombinations(vector<string>& ans, vector<vector<int>>& numVector, string& digits, int index, string& ansElement){
            int num = digits[index] - 48;
            if(index >= digits.size()){
                ans.push_back(ansElement);
                return;
            }
            for(int i = 0; i < numVector[num].size(); i++){
                string temp = ansElement + string(1,numVector[num][i]);
                makeCombinations(ans, numVector, digits, index + 1, temp);
            }
        }
};

// Leetcode solution ends

string formatString(string s){
    if((s.size() - 2) == 0){
        return "";
    } else {
       return s.substr(1, s.size() - 2);
    }
}

void makeVector(vector<string>& vect){
    int numElements;
    cin >> numElements;
    for(int i = 0; i < numElements; i++){
        string temp;
        cin >> temp;
        temp = formatString(temp);
        vect.push_back(temp);
    }
}

// * Note: introduce all strings with the format "string" so they can be converted to: string

void makeTest(){
    vector<string> ans, correctAns;
    string digits;
    cin >> digits;
    digits = formatString(digits);
    makeVector(correctAns);
    ans = Solution().letterCombinations(digits);
    sort(ans.begin(), ans.end());
    sort(correctAns.begin(), correctAns.end());
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