// Source: https://leetcode.com/problems/add-two-numbers/submissions/
// Date: 11.09.2020
// Solution by: David Luna
// Runtime: 12ms
// Memory usage: 7.3 MB

#include <stdio.h>
#include <stdlib.h>

#include "../lib/linkedListUtils/linkedListUtils.h"
#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
	struct ListNode *ans, *ptrAns;
	int carry;

	ans = (struct ListNode *)malloc(sizeof(struct ListNode));
	ans->val = carry = 0;
	ans->next = NULL;
	ptrAns = ans;
	while (l1 || l2) {
		if (l1) {
			carry += l1->val;
			l1 = l1->next;
		}
		if (l2) {
			carry += l2->val;
			l2 = l2->next;
		}
		ans = (ans->next = (struct ListNode *)malloc(sizeof(struct ListNode)));
		ans->val = carry % 10;
		ans->next = NULL;
		carry /= 10;
	}
	if (carry) {
		ans = (ans->next = (struct ListNode *)malloc(sizeof(struct ListNode)));
		ans->val = carry;
		ans->next = NULL;
	}

	ans = ptrAns->next;
	free(ptrAns);
	return ans;
}

// Leetcode solution ends

struct ListNode *captureLinkedList() {
	struct ListNode *ptr;
	vector *vectorList;
	int temp, sizeList;

	vectorList = vector_init_empty();
	scanf("%d", &sizeList);
	while (sizeList--) {
		scanf("%d", &temp);
		vector_push_back(&vectorList, temp);
	}

	ptr = makeLinkedList(vector_get_array(vectorList),
						 vector_get_size(vectorList));
	vector_destructor(vectorList);

	return ptr;
}

void makeTest() {
	struct ListNode *l1, *l2, *ans, *correctAns;

	l1 = captureLinkedList();
	l2 = captureLinkedList();
	correctAns = captureLinkedList();
	ans = addTwoNumbers(l1, l2);

	printf("%s", (compareLinkedLists(ans, correctAns) ? "pass\n" : "fail\n"));

	deleteLinkedList(l1);
	deleteLinkedList(l2);
	deleteLinkedList(ans);
	deleteLinkedList(correctAns);
}

int main() {
	int numTests, i;

	scanf("%d", &numTests);
	for (i = 0; i < numTests; ++i) {
		makeTest();
	}

	return 0;
}
