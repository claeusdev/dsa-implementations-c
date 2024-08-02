#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

typedef struct Node {
	void *data;
	struct Node *next;
} Node ;

typedef struct {
	Node *head;
	int size;
} LinkedList;

void append(LinkedList **l, void *x);
Node* search(LinkedList *l, void *x);
void remove_node(LinkedList **l, void *x);

LinkedList* new_linked_list();

//TODO: add prepend

#endif

