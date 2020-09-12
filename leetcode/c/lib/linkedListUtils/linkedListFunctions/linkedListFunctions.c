// Made by David Luna

#include "./linkedListFunctions.h"

#include <stdlib.h>

bool compareLinkedLists(struct ListNode *l1, struct ListNode *l2) {
	if (!l1 && !l2) {
		return true;
	}
	if ((!l1 && l2) || (l1 && !l2) || (l1->val != l2->val)) {
		return false;
	}
	return compareLinkedLists(l1->next, l2->next);
}

struct ListNode *makeLinkedList(int *list, int size) {
	struct ListNode *head, *temp;

	head = initListNode();
	temp = head;
	while (size-- > 0) {
		temp = (temp->next = initListNodeInt(*(list++)));
	}
	temp = head->next;
	free(head);
	return temp;
}