// qsort.cpp

#include "volsort.h"

#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

int qComparisonInt(const void * a, const void * b) {

	const Node * ia = *(const Node **) a;
	const Node * ib = *(const Node **) b;

	return ia->number - ib->number; //  sorts in ascending order
}

int qComparisonString(const void * a, const void * b) {

	const Node * ia = *(const Node **) a;
	const Node * ib = *(const Node **) b;

	return strcmp(ia->string.c_str(),ib->string.c_str());
}

void qsort_sort(List &l, bool numeric) {

	Node* cur = l.head;
	vector<Node*> vec;
	while(cur != NULL){
		vec.push_back(cur);
		cur = cur->next;
	}
	if(numeric)
		qsort(&vec[0], vec.size(),sizeof(Node*),qComparisonInt);
	else
		qsort(&vec[0], vec.size(),sizeof(Node*),qComparisonString);

	for(size_t i = 0; i < vec.size(); i++){
		vec[i]->next = vec[i+1];
		if(i == vec.size() - 1)
			vec[i]->next = NULL;
	}
	l.head = vec[0];
}
