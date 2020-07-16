//Made by David Luna

#include "./linkedListFunctions.h"
#include <iostream>

ListNode* makeLinkedList(int numElements){
    ListNode* linkedList = nullptr;
    if(numElements > 0){
        linkedList = new ListNode();
        ListNode* tempNode = linkedList;
        for(int i = 0; i < numElements; i++){
            int temp;
            std::cin >> temp;
            linkedList->next = new ListNode(temp);
            linkedList = linkedList->next;
        }
        linkedList = tempNode->next;
        delete tempNode;
    }
    return linkedList;
}

bool compareLinkedLists(ListNode* head1, ListNode* head2){
    bool ans = true;
    while(head1 != nullptr && head2 != nullptr){
        if(head1->val != head2->val){
            ans = false;
            break;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    if((head1 == nullptr && head2 != nullptr) || (head2 == nullptr && head1 != nullptr)){
        ans = false;
    }
    return ans;
}

void deleteLinkedList(ListNode*&head){
    ListNode* temp = head;
    while(head != nullptr){
        head = head->next;
        delete temp;
        temp = head;
    }
}