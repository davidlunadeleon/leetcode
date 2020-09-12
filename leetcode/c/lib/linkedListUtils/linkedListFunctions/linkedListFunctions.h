// Made by David Luna

#pragma once

#ifndef _LINKED_LIST_FUNCTIONS
#define _LINKED_LIST_FUNCTIONS

#include "../listNode/listNode.h"

#include <stdbool.h>

bool compareLinkedLists(struct ListNode *l1, struct ListNode *l2);
struct ListNode *makeLinkedList(int *list, int size);

#endif
