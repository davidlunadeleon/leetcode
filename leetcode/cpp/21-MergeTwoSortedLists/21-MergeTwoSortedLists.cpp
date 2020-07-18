//Source: https://leetcode.com/problems/merge-two-sorted-lists/
//Date: 23.06.2020
//Solution by: David Luna
//Runtime: 4ms
//Memory usage: 14.5 MB

#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(): val(0), next(nullptr) {}
	ListNode(int x): val(x), next(nullptr) {}
	ListNode(int x, ListNode *next): val(x), next(next) {}
};

// Leetcode solution starts

void completeList(ListNode *&ans, ListNode *list){
	while (list != nullptr){
		ans->next = new ListNode(list->val);
		list = list->next;
		ans = ans->next;
	}
}

class Solution{
	public:
		ListNode* mergeTwoLists(ListNode *l1, ListNode *l2){
			ListNode *ans = new ListNode();
			ListNode *headAns = ans;
			while (l1 != nullptr && l2 != nullptr){
				if(l1->val < l2->val){
					ans->next = new ListNode(l1->val);
					l1 = l1->next;
				} else {
					ans->next = new ListNode(l2->val);
					l2 = l2->next;
				}
				ans = ans->next;
			}
			if(l1 != nullptr){
				completeList(ans, l1);
			}
			if(l2 != nullptr){
				completeList(ans, l2);
			}
			ListNode *temp = headAns;
			headAns = headAns->next;
			delete temp;
			return headAns;
		}   
};

// Leetcode solution ends

//Helpful to visualize the process
void printList(ListNode *list){
	ListNode* tempList = list;
	while(tempList->next != nullptr){
		cout << tempList->val << "->";
		tempList = tempList->next;
	}
	cout <<tempList->val << '\n';
}

void makeList(ListNode *&list, ListNode *&head){
	int numElements;
	//Introduce the number of elements in the list
	cin >> numElements;
	//Introduce each element in the list and make a new node for it
	for(int i = 0; i < numElements; i++){
		int tempNum;
		cin >> tempNum;
		list->next = new ListNode(tempNum);
		list = list->next;
	}
	//Move head to the actual start of the list and do come cleanup :)
	ListNode *temp = head;
	head = head->next;
	list = head;
	delete temp;
}

bool compareList(ListNode* l1, ListNode* l2){
	while (l1 != nullptr || l2 != nullptr){
		//If the node in l1 is null but the node in l2 is not, then the lists are not equal. Same in the opposite case.
		if(l1 == nullptr && l2 != nullptr || l1 != nullptr && l2 == nullptr){
			return false;
		}
		//If the values in each node are not the same, the lists are different.
		if(l1->val != l2->val){
			return false;
		}
		l1 = l1->next;
		l2 = l2->next;
	}
	return true;
}

void makeTest(){
	int n;
	ListNode *l1 = new ListNode(), *l2 = new ListNode(), *correctAns = new ListNode();
	ListNode *headL1 = l1, *headL2 = l2, *headCorrectAns = correctAns;
	makeList(l1, headL1);
	makeList(l2, headL2);
	makeList(correctAns, headCorrectAns);
	ListNode *ans = Solution().mergeTwoLists(l1, l2);
	//Uncomment the following lines if you want to visualize the lists
	//printList(l1)
	//printList(l2)
	//printList(correctAns);
	//printList(ans);
	cout << (compareList(ans, headCorrectAns) ? "pass\n" : "fail\n");
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