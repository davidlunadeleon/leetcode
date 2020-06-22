//Source: https://leetcode.com/problems/valid-parentheses/
//Date: 22.06.2020
//Solution by: David Luna
//Runtime: 4ms
//Memory usage: 6.4 MB

#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

// Leetcode solution starts

class Solution{
    public:
        bool isValid(string s){
            stack<char> charStack;
            unordered_map<char, char> charMap({{']','['}, {'}', '{'}, {')', '('}});
            for(int i = 0; i < s.size(); i++){
                switch (s[i]){
                    case '(':
                    case '{':
                    case '[':
                        charStack.push(s[i]);
                        break;
                    case ')':
                    case '}':
                    case ']':
                        if(charStack.empty() || charStack.top() != charMap[s[i]]){
                            return false;
                        } else {
                            charStack.pop();
                        }
                        break;
                    default:
                        break;
                }
            }
            return (charStack.empty() ? true : false);
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

void makeTest(){
    bool correctAns;
    string s;
    //Introduce the correct answer as either 1 or 0
    //Introduce the string s with the following format: "[()]{}[](())"
    cin >> s >> correctAns;
    s = formatString(s);
    cout << (correctAns == Solution().isValid(s) ? "pass\n" : "fail\n");
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