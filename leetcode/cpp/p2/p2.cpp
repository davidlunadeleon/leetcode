// Source: https://leetcode.com/problems/add-two-numbers/
// Date: 17.06.2020
// Solution by: David Luna
// Runtime: 40ms
// Memory usage: 70.3 MB

#include <iostream>
#include <vector>

#include "../lib/linkedListUtils/linkedListUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *ans = new ListNode();
		ListNode *ptrAns = ans;
		int carry = 0;
		while (l1 != nullptr || l2 != nullptr || carry != 0) {
			if (l1 != nullptr) {
				carry += l1->val;
				l1 = l1->next;
			}
			if (l2 != nullptr) {
				carry += l2->val;
				l2 = l2->next;
			}
			ans->next = new ListNode(carry % 10);
			ans = ans->next;
			carry /= 10;
		}
		ListNode *temp = ptrAns;
		ptrAns = ptrAns->next;
		delete temp;
		return ptrAns;
	}
};

// Leetcode solution ends

template <typename T> void makeVectorT(vector<T> &vect) {
	int numElements;
	cin >> numElements;
	for (int i = 0; i < numElements; i++) {
		T temp;
		cin >> temp;
		vect.push_back(temp);
	}
}

void makeTest() {
	bool checkAns = false;
	ListNode *l1, *l2, *ans, *correctAns;
	vector<int> l1vector, l2vector, correctAnsVector;
	makeVectorT(l1vector);
	makeVectorT(l2vector);
	makeVectorT(correctAnsVector);
	l1 = makeLinkedList(l1vector);
	l2 = makeLinkedList(l2vector);
	correctAns = makeLinkedList(correctAnsVector);
	ans = Solution().addTwoNumbers(l1, l2);
	checkAns = compareLinkedLists(ans, correctAns);
	cout << (checkAns ? "pass\n" : "fail\n");
	deleteLinkedList(ans);
	deleteLinkedList(correctAns);
	deleteLinkedList(l1);
	deleteLinkedList(l2);
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