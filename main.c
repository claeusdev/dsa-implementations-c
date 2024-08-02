#include <complex.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"


void print_int(void *data) {
	int *val = (int *) data;
	printf("%d\n", *val);
}

int main() {

	Stack *list = new_stack(5);
	int num_to_stack = 5;
	push(list, &num_to_stack);
	push(list, &num_to_stack);
	push(list, &num_to_stack);
	print_stack(list, print_int);

	return 0;
}
