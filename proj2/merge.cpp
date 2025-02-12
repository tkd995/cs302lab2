// merge.cpp

#include "volsort.h"

#include <iostream>

using namespace std;
// Prototypes

Node *msort(Node *head, bool numeric);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

// Implementations

void merge_sort(List &l, bool numeric) {
	l.head = msort(l.head, numeric);
}

Node *msort(Node *head, bool numeric) {
	if(head->next == nullptr || head == nullptr) return head;//base case

	Node *left, *right;
	split(head, left, right);//divide

	left = msort(left, numeric);
	right = msort(right, numeric);
	return merge(left, right, numeric);//conquer
}

void split(Node *head, Node *&left, Node *&right) {
	if(head->next == nullptr || head == nullptr){//base case
		left = head;
		right = nullptr;
		return;
	}

	Node *fast = head->next;
	Node *slow = head;

	while(fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
	}

	left = head;
	right = slow->next;
	slow->next = nullptr;
}

Node *merge(Node *left, Node *right, bool numeric) {
	Node n;
	Node *head = &n;

	while(left != nullptr && right != nullptr){
		if((numeric && left->number < right->number) || (!numeric && (left->string).compare(right->string) < 0)){
			head->next = left;
			left = left->next;
		}
		else{
			head->next = right;
			right = right->next;
		}
		head = head->next;
	}

	if(left != nullptr) head->next = left;
	else head->next = right;

	return n.next;
}
