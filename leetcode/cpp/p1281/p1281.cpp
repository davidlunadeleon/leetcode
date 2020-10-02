// Source:
// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
// Date: 02.10.2020
// Solution by: David Luna
// Runtime: 0ms
// Memory usage: 6.2 MB

#include <iostream>

// Leetcode solution starts

class Solution {
  public:
	int subtractProductAndSum(int n) {
		int product = 1, sum = 0;

		while (n) {
			product *= n % 10;
			sum += n % 10;
			n /= 10;
		}

		return product - sum;
	}
};

// Leetcode solution ends

void makeTest() {
	int n, ans, correctAns;
	std::cin >> n >> correctAns;

	ans = Solution().subtractProductAndSum(n);
	std::cout << (ans == correctAns ? "pass\n" : "fail\n");
}

int main() {
	int numTests;
	std::cin >> numTests;
	for (int i = 0; i < numTests; i++) {
		makeTest();
	}
	return 0;
}
