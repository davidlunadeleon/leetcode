// Source:
// https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/
// Date: 22.08.2020
// Solution by: David Luna
// Runtime: 136ms
// Memory usage: 68.7 MB

/*
	Note: this solution is based on the observations posted on the discussion
	section of the leetcode problem. My original approach to selecting a
	rectangle was to choose a random index of the list of rectangles but, as
	some explained, this approach is flawed, since it does not result in a
	uniform distribution of points because rectangles can have different areas,
	resulting in different probabilities of choosing a point per rectangle.

	Additional note: the testing for this problem is lacking and I would not
	use it to check the validity of the solution. The test included just checks
	if the returned coordinates (x, y) are inside one of the rectangles. It
	does not take into account the distribution of points.
*/

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	Solution(vector<vector<int>> &rects) {
		int size;

		rectangles = rects;
		size = 0;
		for (vector<int> vect : rects) {
			size += (vect[2] - vect[0] + 1) * (vect[3] - vect[1] + 1);
			areas.push_back(size);
		}
	}

	vector<int> pick() {
		int area, x, y, i;
		vector<int> rect;

		area = rand() % areas.back();
		i = upper_bound(areas.begin(), areas.end(), area) - areas.begin();
		rect = rectangles[i];

		x = rand() % (abs(rect[0] - rect[2]) + 1) + rect[0];
		y = rand() % (abs(rect[1] - rect[3]) + 1) + rect[1];

		return vector<int>{x, y};
	}

  private:
	vector<vector<int>> rectangles;
	vector<int> areas;
};

// Leetcode solution ends

void makeTest() {
	int numPoints, numRects, numOps;
	vector<vector<int>> rects;

	numPoints = 4;
	cin >> numOps >> numRects;
	makeMatrixT(rects, numRects, numPoints);

	Solution *obj = new Solution(rects);
	for (int i = 0; i < numOps; ++i) {
		vector<int> point;
		bool check;

		check = false;
		point = obj->pick();
		for (vector<int> rect : rects) {
			if (point[0] >= rect[0] && point[0] <= rect[2] &&
				point[1] >= rect[1] && point[1] <= rect[3]) {
				check = true;
			}
		}
		if (!check) {
			cout << "fail\n";
			return;
		}
	}
	cout << "pass\n";
	delete obj;
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