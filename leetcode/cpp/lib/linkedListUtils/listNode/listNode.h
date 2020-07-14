//Taken from https://www.leetcode.com

#pragma once

#ifndef _LINKED_LIST_NODE
#define _LINKED_LIST_NODE

struct ListNode {
    int val;
    ListNode* next;
    ListNode();
    ListNode(int x);
    ListNode(int x, ListNode *next);
};

#endif