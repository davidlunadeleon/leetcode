//Source: https://leetcode.com/problems/split-a-string-in-balanced-strings/
//Date: 09.07.2020
//Solution by: David Luna
//Runtime: 4ms
//Memory usage: 6.2 MB

#include <iostream>

using namespace std;

// Leetcode solution starts

class Solution {
    public:
        int balancedStringSplit(string s) {
            int ans = 0, control = 0;
            for(char i : s){
                (i == 'L') ? control++ : control--;
                if(control == 0){
                    ans++;
                }
            }
            return ans;
        }
};

// Leetcode solution ends

void makeTest(){
    string s;
    int correctAns;
    cin >> s >> correctAns;
    cout << (correctAns == Solution().balancedStringSplit(s) ? "pass\n" : "fail\n");
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