//Source: https://leetcode.com/problems/reverse-integer/
//Date: 17.06.2020
//Solution by: David Luna
//Runtime: 4ms
//Memory usage: 5.9 MB

//Note: This may be a little like cheating, but there's no limitation to use only int32_t variables.

#include<iostream>

using namespace std;

// Leetcode solution starts

class Solution {
	public:
		int reverse(int x){
			int64_t ans = 0;
			int ansTemp;
			while (x != 0) {
				ans = ans * 10 + x % 10;
				x = x / 10;
			}
			if(x < 0){
				ans *= -1;
			}
			if(ans > (int64_t)INT32_MAX || ans < (int64_t)INT32_MIN){
				return 0;
			}
			return ans;
		}
};

// Leetcode solution ends

void makeTest(){
	int toCheck, correctAns;
	//Introduce first the number to check, and then the correct answer
	cin >> toCheck >> correctAns;
	int ans = Solution().reverse(toCheck);
	//If the answer is equal to the correct answer previously provided, print pass, if not, print fail.
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