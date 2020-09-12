// Taken from https://www.leetcode.com

#pragma once

#ifndef _LIST_NODE
#define _LIST_NODE

// Struct definition

struct ListNode {
	int val;
	struct ListNode *next;
};

// Creation / destruction management

struct ListNode *initListNode();
struct ListNode *initListNodeInt(int x);
struct ListNode *initListNodeFull(int x, struct ListNode *next);

void deleteLinkedList(struct ListNode *node);

#endif
