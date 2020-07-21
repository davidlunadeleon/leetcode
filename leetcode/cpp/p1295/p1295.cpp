// Source:
// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
// Date: 21.07.2020
// Solution by: David Luna
// Runtime: 12ms
// Memory usage: 10.3 MB

/*
	Note: This solution is based in the one posted in the discussion section
	of the problem.
	My original approach was taking the integer of each index
	in the vector and doing a division by 10 in a while loop until the number
	turned to 0, to obtain the number of digits in the number.
	Since the numbers in the vector cannot be negative, the log10 solution works
	better for the limitations of the problem.
*/

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	int findNumbers(vector<int> &nums) {
		int count = 0;
		for (int num : nums) {
			int temp = log10(num) + 1;
			if (temp % 2 == 0) {
				count++;
			}
		}
		return count;
	}
};

// Leetcode solution ends

template <typename T> void makeVectorT(vector<T> &vect) {
	int numElements;
	cin >> numElements;
	for (int i = 0; i < numElements; i++) {
		T temp;
		cin >> temp;
		vect.push_back(temp);
	}
}

void makeTest() {
	int ans, correctAns;
	vector<int> nums;
	makeVectorT(nums);
	cin >> correctAns;
	ans = Solution().findNumbers(nums);
	cout << (ans == correctAns ? "pass\n" : "fail\n");
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