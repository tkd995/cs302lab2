#include "volsort.h"


List::List() {
	*head = NULL;
	size = 0;

}

List::~List() {
	while(head != NULL){
		node n = head&;
		head = head->next;
		delete n;
	}
}
void List::push_front(const std::string &s) {
	node *n = new node;
	n->number = stoi(s);
	n->string = s;
	if(!head) n->next = NULL;
	else n->next = head;
	size++;
	head = n;
}
