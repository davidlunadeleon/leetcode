// Source: https://leetcode.com/problems/running-sum-of-1d-array/
// Date: 17.07.2020
// Solution by: David Luna
// Runtime: 4ms
// Memory usage: 8.6 MB

#include <iostream>
#include <vector>

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	vector<int> runningSum(vector<int> &nums) {
		int size = nums.size();
		for (int i = 1; i < size; i++) {
			nums[i] += nums[i - 1];
		}
		return nums;
	}
};

// Leetcode solution ends

template <typename T> void makeVectorT(vector<T> &vect, int numElements) {
	for (int i = 0; i < numElements; i++) {
		T temp;
		cin >> temp;
		vect.push_back(temp);
	}
}

void makeTest() {
	int numElements;
	vector<int> nums, correctAns;
	cin >> numElements;
	makeVectorT(nums, numElements);
	makeVectorT(correctAns, numElements);
	nums = Solution().runningSum(nums);
	cout << (nums == correctAns ? "pass\n" : "fail\n");
}

int main() {
	int numTests;
	// Introduce the number of tests to make.
	cin >> numTests;
	for (int i = 0; i < numTests; i++) {
		makeTest();
	}
	return 0;
}