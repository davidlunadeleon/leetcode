// Source: https://leetcode.com/problems/kth-largest-element-in-an-array/
// Date: 03.07.2020
// Solution by: David Luna
// Runtime: 20ms
// Memory usage: 10.4 MB

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	int findKthLargest(vector<int> &nums, int k) {
		priority_queue<int> arrangedElements(nums.begin(), nums.end());
		for (int i = 1; i < k; i++) {
			arrangedElements.pop();
		}
		return arrangedElements.top();
	}
};

// Leetcode solution ends

void makeTest() {
	int numElements, correctAns, kthElement;
	vector<int> nums;
	cin >> numElements;
	for (int i = 0; i < numElements; i++) {
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	cin >> kthElement >> correctAns;
	cout << (correctAns == Solution().findKthLargest(nums, kthElement)
				 ? "pass\n"
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