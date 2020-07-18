//Source: https://leetcode.com/problems/burst-balloons/
//Date: 10.07.2020
//Solution by: David Luna
//Runtime: 20ms
//Memory usage: 8.7 MB

#include <iostream>
#include <vector>

using namespace std;

// Leetcode solution starts

class Solution {
	public:
		int maxCoins(vector<int>& nums) {
			for(int i = 0; i < nums.size(); i++){
				if(nums[i] == 0){
					nums.erase(nums.begin() + i);
					i--;
				}
			}
			nums.insert(nums.begin(), 1);
			nums.push_back(1);
			int size = nums.size();
			vector<vector<int>> matrix(nums.size(), vector<int>(size, 0));
			for(int i = 0; i < size; i++){
				matrix[i][i] = nums[i];
			}
			for(int diag = 2; diag < size; diag++){
				for(int i = 0; i < size - diag; i++){
					matrix[i][i+diag] = auxMaxCoins(nums, matrix, i, i+diag);
				}
			}
			return matrix[0][size - 1];
		}
	private:
		int auxMaxCoins(vector<int> &nums, vector<vector<int>> &matrix, int i, int j){
			int ans = 0;
			for(int k = i + 1; k < j; k++){
				int temp = matrix[i][k] + matrix[k][j] + (nums[i] * nums[k] * nums[j]);
				if(temp > ans){
					ans = temp;
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
	cout << (correctAns == Solution().maxCoins(nums) ? "pass\n" : "fail\n");
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