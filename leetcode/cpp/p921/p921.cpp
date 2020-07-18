//Source: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
//Date: 18.07.2020
//Solution by: David Luna
//Runtime: 0ms
//Memory usage: 6.4 MB

#include <iostream>
#include <stack>

using namespace std;

// Leetcode solution starts

class Solution {
	public:
    	int minAddToMakeValid(string S) {
			stack<char> parenthesesStack;
			int control = 0;
			for(char s: S){
				if(s == '('){
					parenthesesStack.push(s);
				} else if(s == ')'){
					if(parenthesesStack.empty()){
						control++;
					} else {
						parenthesesStack.pop();
					}
				}
			}
			control += parenthesesStack.size();
			return control;
    	}
};

// Leetcode solution ends

string formatString(string s){
	if(s.size() <= 2){
		return "";
	} else{
		return s.substr(1, s.size() - 2);
	}
}

void makeTest(){
	string s;
	int ans, correctAns;
	cin >> s >> correctAns;
	s = formatString(s);
	ans = Solution().minAddToMakeValid(s);
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