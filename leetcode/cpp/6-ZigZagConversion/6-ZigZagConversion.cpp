//Source: https://leetcode.com/problems/zigzag-conversion/
//Date: 27.06.2020
//Solution by: David Luna
//Runtime: 28ms
//Memory usage: 8 MB

#include <iostream>

using namespace std;

// Leetcode solution starts

class Solution {
	public:
		string convert(string s, int numRows) {
			if(numRows == 1){
				return s;
			}
			string ans = "";
			int temp = numRows;
			int startIndex = 0;
			int maxStep = (2 * temp) - 3;
			while(ans.size() != s.size()){
				int step1 = (2 * temp) - 3;
				int step2 = maxStep - 1 - step1;
				int i = startIndex;
				bool boolSwitch = false;
				while (i < s.size()){
					ans.push_back(s[i]);
					if(boolSwitch && step2 >= 0){
						i+= step2 + 1;
					} else {
						i+= step1 + 1;
					}
					boolSwitch = !boolSwitch;
				}
				startIndex++;
				temp--;
				if(temp == 1){
					temp = numRows;
				}
			}
			return ans;
		}
};

// Leetcode solution ends

//Format string from "PAYPALISHIRING" to PAYPALISHIRING.
string formatString(string s){
	if(s.size() <= 2){
		return "";
	} else {
		return s.substr(1, s.size() - 2);
	}
}

void makeTest(){
	string toCheck, correctAns;
	int numRows;
	//Introduce the strings with the format "PAYPALISHIRING";
	cin >> toCheck >> numRows >> correctAns;
	toCheck = formatString(toCheck);
	correctAns = formatString(correctAns);
	cout << (correctAns == Solution().convert(toCheck, numRows) ? "pass\n" : "fail\n");
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