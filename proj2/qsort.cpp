// qsort.cpp

#include "volsort.h"

#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

int qComparisonInt(const void * a, const void * b) {

	const Node * ia = *(const Node **) a;
	const Node * ib = *(const Node **) b;

	return ia->number - ib->number; //  sorts in ascending order
}

void qsort_sort(List &l, bool numeric) {

	Node* cur = l.head;
	if(numeric){
		vector<int> vec;
		while(cur != NULL){
			vec.push_back(stoi(cur->string));
			cur = cur->next;
		}
		qsort(&vec[0], vec.size(),sizeof(int),qComparisonInt );
	}
	else {
		vector<string> vec;
		while(cur != NULL){
			vec.push_back(cur->string);
			cur = cur->next;
		}
		qsort(&vec[0], vec.size(),sizeof(string),qComparisonInt);
	}
}

