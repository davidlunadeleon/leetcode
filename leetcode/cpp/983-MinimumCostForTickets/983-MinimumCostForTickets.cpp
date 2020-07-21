// Source: https://leetcode.com/problems/minimum-cost-for-tickets/
// Date: 05.07.2020
// Solution by: David Luna
// Runtime: 20ms
// Memory usage: 10.9 MB

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// * Note: This solution is based on the solution presented on the same problem
// at leetcode.

// Leetcode solution starts

class Solution {
  public:
	int mincostTickets(vector<int> &days, vector<int> &costs) {
		return dpCost(days, costs, 0);
	}

  private:
	unordered_map<int, int> priceMap;
	int dpCost(vector<int> &days, vector<int> &costs, int index) {
		if (priceMap.find(index) != priceMap.end()) {
			return priceMap[index];
		}
		if (index >= days.size()) {
			return 0;
		}
		vector<int> costVector{
			dpCost(days, costs, searchIndex(days, index, days[index] + 1)) +
				costs[0],
			dpCost(days, costs, searchIndex(days, index, days[index] + 7)) +
				costs[1],
			dpCost(days, costs, searchIndex(days, index, days[index] + 30)) +
				costs[2],
		};
		priceMap.insert(pair<int, int>(
			index, *min_element(costVector.begin(), costVector.end())));
		return priceMap[index];
	}
	int searchIndex(vector<int> &days, int startIndex, int toSearch) {
		int i = startIndex;
		for (i; i < days.size(); i++) {
			if (days[i] >= toSearch) {
				break;
			}
		}
		return i;
	}
};

// Leetcode solution ends

vector<int> makeVector(int numElements) {
	vector<int> vect;
	for (int i = 0; i < numElements; i++) {
		int temp;
		cin >> temp;
		vect.push_back(temp);
	}
	return vect;
}

void makeTest() {
	int numElements, correctAns;
	vector<int> days, costs;
	cin >> numElements;
	days = makeVector(numElements);
	costs = makeVector(3);
	cin >> correctAns;
	cout << (correctAns == Solution().mincostTickets(days, costs) ? "pass\n"
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