// Source: https://leetcode.com/problems/reorder-list/
// Date: 20.08.2020
// Solution by: David Luna
// Runtime: 40ms
// Memory usage: 14.4 MB

#include <iostream>
#include <vector>

#include "../lib/linkedListUtils/linkedListUtils.h"
#include "../lib/vectorUtils/vectorUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	void reorderList(ListNode *head) {
		if (head) {
			ListNode *l1, *l2;

			l1 = l2 = head;
			while (l2->next && l2->next->next) {
				l1 = l1->next;
				l2 = l2->next->next;
			}
			l2 = l1->next;
			l1->next = nullptr;
			l1 = head;
			l2 = reverseList(l2);

			ListNode *temp;

			while (l1 && l2) {
				temp = l1->next;
				l1->next = l2;
				l2 = l2->next;
				l1->next->next = temp;
				l1 = temp;
			}
		}
	}

  private:
	ListNode *reverseList(ListNode *head) {
		ListNode *prev, *temp;

		prev = nullptr;
		while (head) {
			temp = head->next;
			head->next = prev;
			prev = head;
			head = temp;
		}

		return prev;
	}
};

// Leetcode solution ends

void makeTest() {
	int size;
	vector<int> list, correctAnsList;
	ListNode *linkedList, *correctAns;

	cin >> size;
	makeVectorT(list, size);
	makeVectorT(correctAnsList, size);
	linkedList = makeLinkedList(list);
	correctAns = makeLinkedList(correctAnsList);
	Solution().reorderList(linkedList);
	cout << (compareLinkedLists(linkedList, correctAns) ? "pass\n" : "fail\n");

	deleteLinkedList(linkedList);
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