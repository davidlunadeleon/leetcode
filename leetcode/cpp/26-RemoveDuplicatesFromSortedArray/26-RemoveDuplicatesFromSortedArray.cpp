// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Date: 23.06.2020
// Solution by: David Luna
// Runtime: 20ms
// Memory usage: 14.1 MB

#include <iostream>
#include <vector>

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	int removeDuplicates(vector<int> &nums) {
		if (nums.empty()) {
			return nums.size();
		}
		int i = 0, j = 1;
		for (j; j < nums.size(); j++) {
			if (nums[i] != nums[j]) {
				i++;
				nums[i] = nums[j];
			}
		}
		nums.erase(nums.begin() + i + 1, nums.end());
		return nums.size();
	}
};

// Leetcode solution ends

void makeTest() {
	int numElements, correctAns;
	vector<int> nums;
	cin >> numElements;
	for (int i = 0; i < numElements; i++) {
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	cin >> correctAns;
	cout << (correctAns == Solution().removeDuplicates(nums) ? "pass\n"
															 : "fail\n");
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