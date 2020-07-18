//Source: https://leetcode.com/problems/longest-palindromic-substring/
//Date: 18.06.2020
//Solution by: David Luna
//Runtime: 664ms
//Memory usage: 16.7 MB

#include <iostream>
#include <vector>

using namespace std;

// Leetcode solution starts

class Solution {
	public:
		string longestPalindrome(string s){
			if(s.length() <= 1){
				return s;
			}
			int size = s.size(), left = 0, right = 0;
			vector<vector<bool>> array(size,vector<bool>(size, false));
			array[0][0] = true;
			for(int i = 1; i < size; i++){
				array[i][i] = true;
				array[i][i-1] = true;
			}
			for(int diag = 1; diag < size; diag++){
				for(int i = 0; i < size - diag; i++){
					bool temp = s[i] == s[i+diag] && array[i+1][i+diag-1];
					array[i][i+diag] = temp;
					if(temp){
						left = i;
						right = i+diag;
					}
				}
			}
			return s.substr(left, right - left + 1);
		}
};

// Leetcode solution ends

bool checkAns(vector<string> possibleAns, string s){
	string ans = Solution().longestPalindrome(s);
	for(int i = 0; i < possibleAns.size(); i++){
		if(ans == possibleAns[i]){
			return true;
		}
	}
	cout << '\n' << s << "\n\n";
	return false;
}

void makeTest(){
	int numAns;
	string s;
	vector<string> possibleAns;
	//Introduce the string to check
	cin >> s;
	//Introduce the number of possible answers
	cin >> numAns;
	//Introduce the possible answers
	for(int i = 0; i < numAns; i++){
		string temp;
		cin >> temp;
		possibleAns.push_back(temp);
	}
	cout << (checkAns(possibleAns, s) ? "pass\n" : "fail\n");
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
