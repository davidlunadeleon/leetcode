//Source: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
//Date: 14.07.2020
//Solution by: David Luna
//Runtime: 0ms
//Memory usage: 8.4 MB

#include <iostream>
#include "../lib/linkedListUtils/linkedListUtils.h"

using namespace std;

// Leetcode solution starts

class Solution {
	public:
		int getDecimalValue(ListNode* head) {
			int ans = 0;
			while(head != nullptr){
				ans <<= 1;
				ans += head->val;
				head = head->next;
			}
			return ans;
		}
};

// Leetcode solution ends

void makeTest(){
	int numElements, correctAns;
	cin >> numElements;
	ListNode* linkedList = makeLinkedList(numElements);
	cin >> correctAns;
	cout << (correctAns == Solution().getDecimalValue(linkedList) ? "pass\n" : "fail\n");
	deleteLinkedList(linkedList);
}

int main(){
	int numTests;
	//Introduce the number of tests to make.
	cin >> numTests;
	for(int i = 0; i < numTests; i++){
		makeTest();
	}
	return 0;
}