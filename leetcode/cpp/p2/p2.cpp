// Source: https://leetcode.com/problems/add-two-numbers/
// Date: 17.06.2020
// Solution by: David Luna
// Runtime: 44ms
// Memory usage: 71.2 MB

#include <iostream>
#include <vector>

#include "../lib/linkedListUtils/linkedListUtils.h"
#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

class Solution {
  public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *ans, *ptrAns;
		int carry;

		ans = new ListNode();
		ptrAns = ans;
		carry = 0;
		while (l1 || l2) {
			if (l1) {
				carry += l1->val;
				l1 = l1->next;
			}
			if (l2) {
				carry += l2->val;
				l2 = l2->next;
			}
			ans = (ans->next = new ListNode(carry % 10));
			carry /= 10;
		}
		if (carry) {
			ans->next = new ListNode(carry);
		}

		ans = ptrAns->next;
		delete ptrAns;
		return ans;
	}
};

// Leetcode solution ends

void makeTest() {
	ListNode *l1, *l2, *ans, *correctAns;
	std::vector<int> l1vector, l2vector, correctAnsVector;

	makeVectorT(l1vector);
	makeVectorT(l2vector);
	makeVectorT(correctAnsVector);
	l1 = makeLinkedList(l1vector);
	l2 = makeLinkedList(l2vector);
	correctAns = makeLinkedList(correctAnsVector);

	ans = Solution().addTwoNumbers(l1, l2);
	std::cout << (compareLinkedLists(ans, correctAns) ? "pass\n" : "fail\n");

	deleteLinkedList(ans);
	deleteLinkedList(correctAns);
	deleteLinkedList(l1);
	deleteLinkedList(l2);
}

int main() {
	int numTests;
	std::cin >> numTests;
	for (int i = 0; i < numTests; i++) {
		makeTest();
	}
	return 0;
}