// Source: https://leetcode.com/problems/robot-bounded-in-circle/
// Date: 17.09.2020
// Solution by: David Luna
// Runtime: 0ms
// Memory usage: 6 MB

#include <iostream>

// Leetcode solution starts

struct Movement {
	int x, y, d;

	Movement() : x(0), y(0), d(0) {}

	void moveForward() {
		switch (d) {
		case 0:
			++y;
			break;
		case 1:
			++x;
			break;
		case 2:
			--y;
			break;
		case 3:
			--x;
			break;
		default:
			break;
		}
	}

	void rotateLeft() { d = (d + 1) % 4; }

	void rotateRight() {
		--d;
		if (d < 0) {
			d = 3;
		}
	}
};

class Solution {
  public:
	bool isRobotBounded(std::string instructions) {
		Movement m;

		for (char c : instructions) {
			switch (c) {
			case 'G':
				m.moveForward();
				break;
			case 'R':
				m.rotateRight();
				break;
			case 'L':
				m.rotateLeft();
				break;
			default:
				break;
			}
		}

		if ((m.x == 0 && m.y == 0) || m.d != 0) {
			return true;
		}
		return false;
	}
};

// Leetcode solution ends

void makeTest() {
	std::string instructions;
	bool ans, correctAns;

	std::cin >> instructions >> correctAns;

	ans = Solution().isRobotBounded(instructions);
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
