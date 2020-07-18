//Source: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
//Date: 23.06.2020
//Solution by: David Luna
//Runtime: 4ms
//Memory usage: 10.4 MB

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

class Solution{
	public:
		ListNode* removeNthFromEnd(ListNode* head, int n){
			ListNode *nth = head, *auxNode = head;
			for(int i = 0; i < n; i++){
				auxNode = auxNode->next;
			}
			if(auxNode != nullptr){
				while (auxNode->next != nullptr){
					auxNode = auxNode->next;
					nth = nth->next;
				}
				auxNode = nth->next;
				nth->next = nth->next->next;
				delete auxNode;
			} else {
				head = head->next;
				delete nth;
			}
			return head;
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
	ListNode *l1 = new ListNode(), *correctAns = new ListNode();
	ListNode *headL1 = l1, *headCorrectAns = correctAns;
	makeList(l1, headL1);
	//Introduce the Nth element from the end to remove
	cin >> n;
	makeList(correctAns, headCorrectAns);
	ListNode *ans = Solution().removeNthFromEnd(l1, n);
	//Uncomment the following lines if you want to visualize the lists
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