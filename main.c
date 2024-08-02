#include <complex.h>
#include <stdio.h>
#include <stdlib.h>

#include "ll.h"
#include "stack.h"


void print_int(void *data) {
	int *val = (int *) data;
	printf("%d\n", *val);
}

int main() {

	Stack *stack = new_stack(5);
	int num_to_stack = 5;
	push(stack, &num_to_stack);
	push(stack, &num_to_stack);
	push(stack, &num_to_stack);
	print_stack(stack, print_int);

	// linked lists
	// just adding these tests here i've
	// just realized these names suck
	LinkedList *ls = new_linked_list();
	int nana = 100;
	int kwame = 1000;
	int mama = 50000;
	append(&ls, &nana);
	append(&ls, &kwame);
	append(&ls, &mama);

	printf("List size: %d\n", ls->size);
	Node *currNode = ls->head;
	while (currNode != NULL) {
		printf("data -> %d\n", *(int*) currNode->data);
		currNode = currNode->next;
	}
	remove_node(&ls, &nana);
	printf("List size: %d\n", ls->size);
	Node *ne = ls->head;
	while (ne != NULL) {
		printf("data -> %d\n ", *(int*) ne->data);
		ne = ne->next;
	}
	return 0;
}
