#include <stdio.h>
#include "ll.h"

LinkedList* new_linked_list(){
	LinkedList *list = malloc(sizeof(LinkedList));
	list->head = NULL;
	list->size = 0;
	return list;
}

Node* search(LinkedList *l, void *x) {
	Node *current = l->head;

	if(l == NULL) {
		return NULL;
	}

	if(l->head == x){
		return l->head;
	} else {
		return search(l, x);
	}
}

void remove_node(LinkedList **l, void *x){
	LinkedList *lst = *l;
	if(lst->head == NULL || lst == NULL) return;

	Node *current = lst->head;
	Node *prev = NULL;

	while (current != NULL) {
		if (current->data == x) {
			if(prev == NULL) {
				lst->head = current->next;
			} else {
				prev->next = current->next;
			}
			free(current);
			lst->size -= 1;
			return;
		}
		prev = current;
		current = current->next;
	}
}

void append(LinkedList **l, void *val){
	Node *new_node = malloc(sizeof(Node));
	new_node->data = val;
	new_node->next = (*l)->head;
	(*l)->head = new_node;
	(*l)->size += 1;
}


