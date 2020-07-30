// Made By David Luna

#pragma once

#ifndef _LINKED_LIST_FUNCTIONS
#define _LINKED_LIST_FUNCTIONS

#include "../listNode/listNode.h"
#include <iostream>
#include <vector>

ListNode *makeLinkedList(std::vector<int> list);
bool compareLinkedLists(ListNode *head1, ListNode *head2);
void deleteLinkedList(ListNode *&head);

#endif