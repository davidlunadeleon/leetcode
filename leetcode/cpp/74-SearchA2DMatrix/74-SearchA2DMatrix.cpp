//Source: https://leetcode.com/problems/search-a-2d-matrix/
//Date: 02.07.2020
//Solution by: David Luna
//Runtime: 16 ms
//Memory usage: 11.5 MB

#include <iostream>
#include <vector>

using namespace std;

// Leetcode solution starts

class Solution {
	public:
		bool searchMatrix(vector<vector<int>>& matrix, int target) {
			if(matrix.empty() || matrix[0].empty()){
				return false;
			}
			int numCols = matrix[0].size() - 1;
			for(int i = 0; i < matrix.size(); i++){
				if(matrix[i][numCols] >= target && matrix[i][0] <= target){
					return binarySearch(matrix[i], target);
				}
			}
			return false;
		}
	private:
		bool binarySearch(vector<int> row, int target){
			int left = 0, right = row.size() - 1;
			do {
				int middle = (right - left) / 2 + left;
				if(target == row[middle]){
					return true;
				}
				if(target > row[middle]){
					left = middle + 1;
				} else {
					right = middle - 1;
				}
			} while (left <= right);
			return false;
		}
};

// Leetcode solution ends

vector<vector<int>> makeMatrix(){
	int numRows, numColums;
	vector<vector<int>> matrix;
	cin >> numRows >> numColums;
	for(int i = 0; i < numRows; i++){
		vector<int> tempVector;
		for(int j = 0; j < numColums; j++){
			int tempNum;
			cin >> tempNum;
			tempVector.push_back(tempNum);
		}
		matrix.push_back(tempVector);
	}
	return matrix;
}

void makeTest(){
	vector<vector<int>> matrix;
	bool correctAns;
	int target;
	matrix = makeMatrix();
	cin >> correctAns >> target;
	bool ans = Solution().searchMatrix(matrix, target);
	cout << (correctAns == Solution().searchMatrix(matrix, target) ? "pass\n" : "fail\n");
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