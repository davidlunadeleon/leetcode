//Source: https://leetcode.com/problems/palindrome-number/
//Date: 17.06.2020
//Solution by: David Luna
//Runtime: 8ms
//Memory usage: 5.9 MB

#include <iostream>

using namespace std;

// Leetcode solution starts

class Solution{
    public:
        bool isPalindrome(int x){
            if(x < 0){
                return false;
            }
            int ansTemp = x;
            int64_t ans = 0;
            while(ansTemp != 0){
                ans = ans * 10 + ansTemp % 10;
                ansTemp /= 10;
            }
            if(ans > (int64_t)INT32_MAX) { 
                return false;
            }
            return ans == x ? true : false;
        }
};

// Leetcode solution ends

void makeTest(){
    int numOriginal;
    bool correctAns;
    //Introduce the number to verify and the correct answer. Note: Introduce the correct answer as either 1 or 0.
    cin >> numOriginal >> correctAns;
    //If the answer is equal to the correct answer previously provided, print pass, if not, print fail.
    cout << (Solution().isPalindrome(numOriginal) == correctAns ? "pass\n" : "fail\n");
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