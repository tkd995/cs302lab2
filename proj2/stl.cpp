// stl.cpp

#include "volsort.h"

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool nnc(Node *a, Node *b){//number compare
	return a->number < b->number;
}

bool nsc(Node *a, Node *b){//string compare
	return (a->string).compare(b->string) < 0;
}

void stl_sort(List &l, bool numeric) {
	vector<Node *> n;
	Node* head = l.head;

	while(head != nullptr){//read into vector
		n.push_back(head);
		head = head->next;
	}

	if(numeric) sort(n.begin(), n.end(), nnc);
	else sort(n.begin(), n.end(), nsc);

	l.head = n[0];
	Node * temp = l.head;
	for(int i = 1; i < (int)n.size(); ++i){//rewrite to linked list
		temp->next = n[i];
		temp = temp->next;
	}

	temp->next = nullptr;
}
