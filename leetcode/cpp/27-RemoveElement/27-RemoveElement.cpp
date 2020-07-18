//Source: https://leetcode.com/problems/remove-element/
//Date: 29.06.2020
//Solution by: David Luna
//Runtime: 4ms
//Memory usage: 8.9 MB

#include <iostream>
#include <vector>

using namespace std;

// Leetcode solution starts

class Solution {
	public:
		int removeElement(vector<int>& nums, int val) {
			for(int i = 0; i < nums.size(); i++){
				if(nums[i] == val){
					nums.erase(nums.begin() + i);
					i--;
				}
			}
			return nums.size();
		}
};

// Leetcode solution ends

void makeTest(){
	int numElements, val, correctAns;
	vector<int> nums;
	cin >> numElements;
	for(int i = 0; i < numElements; i++){
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	cin >> val >> correctAns;
	cout << (correctAns == Solution().removeElement(nums, val) ? "pass\n" : "fail\n");
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