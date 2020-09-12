// Taken from https://www.leetcode.com

#include "listNode.h"

#include <stddef.h>
#include <stdlib.h>

struct ListNode *initListNode() {
	return initListNodeInt(0);
}

struct ListNode *initListNodeInt(int x) {
	return initListNodeFull(x, NULL);
}

struct ListNode *initListNodeFull(int x, struct ListNode *next) {
	struct ListNode *ptr = malloc(sizeof(struct ListNode));
	ptr->val = x;
	ptr->next = next;

	return ptr;
}

void deleteLinkedList(struct ListNode *node) {
	if (node) {
		deleteLinkedList(node->next);
		free(node);
	}
}