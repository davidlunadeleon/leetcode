//Source: https://leetcode.com/problems/number-of-good-pairs/
//Date: 12.07.2020
//Solution by: David Luna
//Runtime:
//Memory usage:

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Leetcode solution starts

class Solution {
	public:
		int numIdenticalPairs(vector<int>& nums) {
			unordered_map<int, int> numMap;
			int ans = 0;
			for(int num : nums){
				if(numMap.find(num) == numMap.end()){
					numMap.insert(pair<int,int>(num,0));
				} else {
					numMap[num]++;
					ans += numMap[num];
				}
			}
			return ans;
		}
};

// Leetcode solution ends

vector<int> makeIntVector(int numElements){
	vector<int> ans;
	for(int i = 0; i < numElements; i++){
		int temp;
		cin >> temp;
		ans.push_back(temp);
	}
	return ans;
}

void makeTest(){
	int numElements, correctAns;
	vector<int> nums;
	cin >> numElements;
	nums = makeIntVector(numElements);
	cin >> correctAns;
	cout << (correctAns == Solution().numIdenticalPairs(nums) ? "pass\n" : "fail\n");
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