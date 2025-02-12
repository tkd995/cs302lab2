// quick.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {
	qsort(l.head,numeric);
}

Node *qsort(Node *head, bool numeric) {	
	if(head == NULL || head->next == NULL)//Base Case: 0 or 1 element in the partition
		return head;
	Node* left;
	Node* right;
	Node* pivot = head;//pivot is first element
	partition(head, pivot, left, right, numeric);
	qsort(left, numeric); qsort(right,numeric);
	concatenate(left,pivot);//re-add the pivot
	concatenate(left,right);
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
	Node* leftTail = left;
	Node* rightTail = right;
	while(leftTail != NULL)
		leftTail = leftTail->next;
	while(rightTail != NULL)
		rightTail = rightTail->next;

	Node* cur = head->next;
	if(numeric){
		while(cur != NULL){
			if(stoi(cur->string) < stoi(pivot->string)){	
				*leftTail = *cur;
				leftTail = leftTail->next;
				leftTail = NULL;
			}
			else {
				*rightTail = *cur;
				rightTail = rightTail->next;
				rightTail = NULL;
			}
			cur = cur->next;
		}
	}
	else {//not numeric
		while(cur != NULL){
			if((cur->string).compare((pivot->string)) <= 0){	
				*leftTail = *cur;
				leftTail = leftTail->next;
				leftTail = NULL;
			}
			else {
				*rightTail = *cur;
				rightTail = rightTail->next;
				rightTail = NULL;
			}
			cur = cur->next;
		}
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

