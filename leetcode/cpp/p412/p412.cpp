// Source: https://leetcode.com/problems/fizz-buzz/
// Date: 17.07.2020
// Solution by: David Luna
// Runtime: 4ms
// Memory usage: 7.3 MB

#include <iostream>
#include <vector>

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	vector<string> fizzBuzz(int n) {
		vector<string> ans(n, "");
		for (int i = 0; i < n; i++) {
			int num = i + 1;
			string fizzbuzz = (num) % 3 == 0 ? "Fizz" : "";
			fizzbuzz += (num) % 5 == 0 ? "Buzz" : "";
			ans[i] = fizzbuzz == "" ? to_string(num) : fizzbuzz;
		}
		return ans;
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
	vector<string> fizzbuzz, correctAns;
	cin >> numElements;
	fizzbuzz = Solution().fizzBuzz(numElements);
	makeVectorT(correctAns, numElements);
	cout << (fizzbuzz == correctAns ? "pass\n" : "fail\n");
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