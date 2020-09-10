// Source: https://leetcode.com/problems/bulls-and-cows/
// Date: 10.09.2020
// Solution by: David Luna
// Runtime: 4ms
// Memory usage: 6.5 MB

#include <algorithm>
#include <iostream>

// Leetcode solution starts

class Solution {
  public:
	std::string getHint(std::string secret, std::string guess) {
		const int numElements = 10; // From 0 to 9
		int bulls, cows, size, i;
		int times[numElements]{0}, check[numElements]{0};

		size = secret.size();
		bulls = cows = 0;
		for (i = 0; i < size; ++i) {
			if (guess[i] == secret[i]) {
				++bulls;
			} else {
				check[secret[i] - '0']++;
				times[guess[i] - '0']++;
			}
		}
		for (i = 0; i < numElements; ++i) {
			cows += std::min(check[i], times[i]);
		}

		return std::to_string(bulls) + "A" + std::to_string(cows) + "B";
	}
};

// Leetcode solution ends

void makeTest() {
	std::string secret, guess, ans, correctAns;

	std::cin >> secret >> guess >> correctAns;
	ans = Solution().getHint(secret, guess);
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
