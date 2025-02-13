// quick.cpp

#include "volsort.h"

#include <iostream>
#include <cstring>

using namespace std;

// Prototypes

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {
	l.head = qsort(l.head,numeric);
}

Node *qsort(Node *head, bool numeric) {	
	cout<<"qsort"<<endl;
	if(head == NULL || head->next == NULL)//Base Case: 0 or 1 element in the partition
		return head;

	Node* left = nullptr, *right = nullptr;
	Node* pivot = head;//pivot is first element
	partition(pivot->next, pivot, left, right, numeric);//divide

	left = qsort(left, numeric); 
	right = qsort(right,numeric);

	pivot->next = right;
	return concatenate(left,pivot);//conquer
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
	cout<<"partition"<<endl;
	
	Node* leftTail = nullptr, *rightTail = nullptr;
	/*
	while(leftTail != NULL && leftTail->next != NULL)
		leftTail = leftTail->next;
	while(rightTail != NULL && leftTail->next != NULL)
		rightTail = rightTail->next;
	cout<<"here"<<endl;*/
	Node* cur = head;
	while(cur != NULL){
		Node* next = cur->next;
		if(numeric){
			if(cur->number < pivot->number){
				if(left == nullptr) {
					left = cur;
					leftTail = left;
				}
				else{
					leftTail->next = cur;
					leftTail = leftTail->next;
				}
			}
			else {
				if(right == nullptr){
					right = cur;
					rightTail = right;
				}
				else{
					rightTail->next = cur;
					rightTail = rightTail->next;
				}
			}
		}
		else { //if not numeric
			if((cur->string).compare(pivot->string) < 0){	
				if(left == nullptr){
					left = cur;
					leftTail = left;
				}
				else{
					leftTail->next = cur;
					leftTail = leftTail->next;
				}
			}
			else {
				if(right == nullptr) {
					right = cur;
					rightTail = right;
				}
				else{
					rightTail->next = cur;
					rightTail = rightTail->next;
				}
			}
		}
		cur = next;
	}
	if (leftTail != nullptr) leftTail->next = nullptr;
	if (rightTail != nullptr) rightTail->next = nullptr;
}
Node *concatenate(Node *left, Node *right) {
	cout<<"cat"<<endl;
	if(left == NULL) return right;

	Node* cur = left;
	while(cur->next != NULL)//proceed to end of the left partition
		cur = cur->next;

	cur->next = right;//then connect it to the right partition
	return left;
}
