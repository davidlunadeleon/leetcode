// Source: https://leetcode.com/problems/reverse-linked-list/
// Date: 06.08.2020
// Solution by: David Luna
// Runtime: 8ms
// Memory usage: 7.8 MB

#include <iostream>

#include "../lib/linkedListUtils/linkedListUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	ListNode *reverseList(ListNode *head) {
		if (head) {
			if (head->next) {
				ListNode *nextNode, *tempNode;
				nextNode = head->next;
				head->next = nullptr;
				do {
					tempNode = nextNode;
					nextNode = nextNode->next;
					tempNode->next = head;
					head = tempNode;
				} while (nextNode);
				head = tempNode;
			}
		}
		return head;
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
	vector<int> nums, correctAnsVect;
	ListNode *ans, *correctAns;
	makeVectorT(nums);
	makeVectorT(correctAnsVect);
	ans = makeLinkedList(nums);
	correctAns = makeLinkedList(correctAnsVect);
	ans = Solution().reverseList(ans);
	cout << (compareLinkedLists(ans, correctAns) ? "pass\n" : "fail\n");
	deleteLinkedList(ans);
	deleteLinkedList(correctAns);
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