//Source: https://leetcode.com/problems/container-with-most-water/
//Date: 25.06.2020
//Solution by: David Luna
//Runtime: 40ms
//Memory usage: 14.3 MB

#include <iostream>
#include <vector>

using namespace std;

// Leetcode solution starts

class Solution {
	public:
		int maxArea(vector<int>& height) {
			int left = 0, right = height.size() - 1;
			int ans = getArea(height, left, right);
			while(left != right){
				int aux = 0;
				if(height[left] > height[right]){
					aux = right;
					while(left != right && right > 0 && height[right] <= height[aux]){
						right--;
					}
				} else {
					aux = left;
					while(left != right && left < height.size() - 1 && height[left] <= height[aux]){
						left++;
					}
				}
				int temp = getArea(height, left, right);
				if(temp > ans){
					ans = temp;
				}
			}
			return ans;
		}
	private:
		int getArea(vector<int>& height, int &left, int &right){
			return (right - left) * (height[left] > height[right] ? height[right] : height[left]);
		}
};

// Leetcode solution ends

void makeTest(){
	int numElements, correctAns;
	vector<int> height;
	cin >> numElements;
	for(int i = 0; i < numElements; i++){
		int temp;
		cin >> temp;
		height.push_back(temp);
	}
	cin >> correctAns;
	cout << (correctAns == Solution().maxArea(height) ? "pass\n" : "fail\n");
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