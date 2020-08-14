// Source: https://leetcode.com/problems/iterator-for-combination/
// Date: 13.08.2020
// Solution by: David Luna
// Runtime: 20ms
// Memory usage: 12.3 MB

/*
	Note: This solution is inspired by the one suggested on the discussion
	section of the problem. The main difference from other implementations
	is that here, the combinations are calculated as the next method is called,
	not from the very beginning.

	My original approach to the problem was using a vector indexes to keep
	control of the position to each iterator of the combinations. Using an
	int as a bit array was helpful because keeping control of the moving
	indexes was easier just using substraction and checking if the number
	of set bits is correct or not.
*/

#include <iostream>
#include <vector>

#include "../lib/vectorUtils/vectorUtils.h"

using namespace std;

// Leetcode solution starts

class CombinationIterator {
  public:
	CombinationIterator(string characters, int combinationLength) {
		cLen = combinationLength;
		chars = characters;
		int size = chars.size();

		bitMap = 0;
		for (int i = 0; i < cLen; i++) {
			bitMap <<= 1;
			bitMap++;
		}
		finalCombination = bitMap;
		for (int i = cLen; i < size; i++) {
			bitMap <<= 1;
		}
	}

	string next() {
		int temp, it, size;
		string ans;

		temp = bitMap;
		size = chars.size() - 1;
		ans = "";
		it = 0;

		while (temp) {
			if (temp & 1) {
				ans.insert(0, 1, chars[size - it]);
			}
			temp >>= 1;
			it++;
		}

		makeNextComb();
		return ans;
	}

	bool hasNext() { return bitMap == 0 ? false : true; }

  private:
	int bitMap, cLen, finalCombination;
	string chars;

	void makeNextComb() {
		int numBits, temp, times;
		temp = bitMap;
		times = 1;

		do {
			numBits = 0;
			temp = bitMap - times;
			times++;
			while (temp > 0) {
				numBits += temp & 1;
				temp >>= 1;
			}
		} while (numBits != cLen && numBits != 0);
		bitMap -= --times;
	}
};

// Leetcode solution ends

void makeTest() {
	string chars;
	int cLen;
	CombinationIterator *obj;
	vector<string> ans, correctAns;
	vector<char> operations;

	cin >> chars >> cLen;
	obj = new CombinationIterator(chars, cLen);

	makeVectorT(operations);
	makeVectorT(correctAns);

	for (uint64_t i = 0; i < operations.size(); i++) {
		char c;

		c = operations[i];

		switch (c) {
		case 'n':
			ans.push_back(obj->next());
			break;
		case 'h':
			ans.push_back(obj->hasNext() ? "1" : "0");
			break;
		default:
			break;
		}
	}

	cout << (ans == correctAns ? "pass\n" : "fail\n");

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