// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Date: 30.07.2020
// Solution by: David Luna
// Runtime: 16ms
// Memory usage: 11.2 MB

#include <iostream>
#include <vector>

#include "../lib/linkedListUtils/linkedListUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
  public:
	ListNode *deleteDuplicates(ListNode *head) {
		ListNode *ans = head;
		if (head) {
			ListNode *newHead = new ListNode(0, head);
			ListNode *curr = head, *currPrev = newHead;
			while (curr && curr->next) {
				if (curr->val == curr->next->val) {
					int val = curr->val;
					while (currPrev->next && currPrev->next->val == val) {
						currPrev->next = curr->next;
						delete curr;
						curr = currPrev->next;
					}
				} else {
					currPrev = curr;
					curr = curr->next;
				}
			}
			ans = newHead->next;
			delete newHead;
		}
		return ans;
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
	vector<int> list, correctAnsList;
	ListNode *ans, *correctAns;
	bool ansCheck = false;

	makeVectorT(list);
	makeVectorT(correctAnsList);
	ans = makeLinkedList(list);
	correctAns = makeLinkedList(correctAnsList);
	ans = Solution().deleteDuplicates(ans);
	ansCheck = compareLinkedLists(ans, correctAns);
	cout << (ansCheck ? "pass\n" : "fail\n");

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