
// Source: https://leetcode.com/problems/3sum/
// Date: 30.06.2020
// Solution by: David Luna
// Runtime: 68 ms
// Memory usage: 14.2 MB

/*
	Note: this solution is completely based on the solution to the problem 4 sum
   in leetcode.
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	vector<vector<int>> fourSum(vector<int> &nums, int target) {
		sort(nums.begin(), nums.end());
		set<vector<int>> ans = nSum(nums, 4, target, 0);
		vector<vector<int>> ansVector;
		for (auto i = ans.begin(); i != ans.end(); i++) {
			vector<int> tempVector = *i;
			ansVector.push_back(tempVector);
		}
		return ansVector;
	}

  private:
	set<vector<int>> nSum(vector<int> &nums, int numSum, int target,
						  int index) {
		if (numSum == 2) {
			return twoSum(nums, target, index);
		}
		set<vector<int>> ans;
		for (int i = index; i < nums.size(); i++) {
			if (i == index || (nums[i] != nums[i - 1])) {
				set<vector<int>> temp =
					nSum(nums, numSum - 1, target - nums[i], i + 1);
				for (auto it = temp.begin(); it != temp.end(); it++) {
					vector<int> tempVector = *it;
					tempVector.push_back(nums[i]);
					sort(tempVector.begin(), tempVector.end());
					ans.insert(tempVector);
				}
			}
		}
		return ans;
	}
	set<vector<int>> twoSum(vector<int> &nums, int target, int index) {
		int left = index, right = nums.size() - 1;
		set<vector<int>> ans;
		while (left < right) {
			int sum = nums[left] + nums[right];
			if (sum > target) {
				right--;
			} else if (sum < target) {
				left++;
			} else {
				vector<int> tempVector{nums[left], nums[right]};
				ans.insert(tempVector);
				left++;
				right--;
			}
		}
		return ans;
	}
};

// Leetcode solution ends

void makeVector(vector<int> &toMake) {
	int numElements;
	cin >> numElements;
	for (int i = 0; i < numElements; i++) {
		int temp;
		cin >> temp;
		toMake.push_back(temp);
	}
	sort(toMake.begin(), toMake.end());
}

void makeTest() {
	int numAns, target;
	vector<int> toCheck;
	vector<vector<int>> correctAns, ans;
	makeVector(toCheck);
	cin >> target >> numAns;
	for (int i = 0; i < numAns; i++) {
		vector<int> temp;
		makeVector(temp);
		correctAns.push_back(temp);
	}
	ans = Solution().fourSum(toCheck, target);
	sort(ans.begin(), ans.end());
	sort(correctAns.begin(), correctAns.end());
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