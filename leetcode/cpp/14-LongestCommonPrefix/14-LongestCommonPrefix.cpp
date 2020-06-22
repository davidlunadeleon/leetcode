
//Source: https://leetcode.com/problems/longest-common-prefix/
//Date: 22.06.2020
//Solution by: David Luna
//Runtime: 8ms
//Memory usage: 9.3 MB

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Leetcode solution starts

bool compareStrings(string &string1, string &string2){
    return (string1.size() < string2.size());
}

class Solution{
    public:
        string longestCommonPrefix(vector<string>& strs){
            int size = strs.size();
            if(size == 0){
                return "";
            } else if(size == 1){
                return strs[0];
            }
            string ans = "";
            sort(strs.begin(), strs.end(), compareStrings);
            for(int i = 0; i < strs[0].size(); i++){
                for(int j = 1; j < size; j++){
                    if(strs[j][i] != strs[0][i]){
                        return ans;
                    }
                }
                ans += strs[0][i];
            }
            return ans;
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
    vector<string> vectStrings;
    string correctAns;
    int numElements;
    //Introduce the number of elements in the vector of strings to check
    cin >> numElements;
    for(int i = 0; i < numElements; i++){
        string temp;
        //Introduce the element with the following format: "element". This is in case you want to use an empty string.
        cin >> temp;
        temp = formatString(temp);
        vectStrings.push_back(temp);
    }
    //Introduce the correct answer with the same "answer" format.
    cin >> correctAns;
    correctAns = formatString(correctAns);
    cout << (correctAns == Solution().longestCommonPrefix(vectStrings) ? "pass\n" : "fail\n");
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