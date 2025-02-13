// quick.cpp

#include "volsort.h"

#include <iostream>
#include <cstring>

// Prototypes

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {
	l.head = qsort(l.head,numeric);
}

Node *qsort(Node *head, bool numeric) {	
	if(head == NULL || head->next == NULL)//Base Case: 0 or 1 element in the partition
		return head;

	Node* left;
	Node* right;
	Node* pivot = head;//pivot is first element
	partition(head, pivot, left, right, numeric);//divide

	qsort(left, numeric); qsort(right,numeric);
	concatenate(left,pivot);//re-add the pivot
	return concatenate(left,right);//conquer
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {

	Node* leftTail = left;
	Node* rightTail = right;
	while(leftTail != NULL && leftTail->next != NULL)
		leftTail = leftTail->next;
	while(rightTail != NULL && leftTail->next != NULL)
		rightTail = rightTail->next;

	Node* cur = head->next;
	while(cur != NULL){
		Node* next = cur->next;
		if(numeric){
			if(cur->number < pivot->number){	
				leftTail = cur;
				leftTail->next = NULL;
			}
			else {
				rightTail = cur;
				rightTail->next = NULL;
			}
		}
		else { //if not numeric
			if(strcmp(cur->string.c_str(), pivot->string.c_str())){	
				leftTail = cur;
				leftTail->next = NULL;
			}
			else {
				rightTail = cur;
				rightTail->next = NULL;
			}
		}
		cur = next;
	}
}
Node *concatenate(Node *left, Node *right) {
	if(left == NULL)//left partition is empty
		return right;
	Node* cur = left;
	while(cur != NULL)//proceed to end of the left partition
		cur = cur->next;
	cur->next = right;//then connect it to the right partition
	return left;
}

