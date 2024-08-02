#include <complex.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	void** data;
	size_t size;
	int capacity;
} Stack;

typedef void (*DisplayStack)(void *);

Stack* new_stack(int capacity){
	Stack *s = malloc(sizeof(Stack));
	if(s == NULL){
		fprintf(stderr, "Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	s->data = malloc(capacity * sizeof(void *));
	if(s->data == NULL){
		fprintf(stderr, "Memory allocation failed");
		free(s);
		exit(EXIT_FAILURE);
	}

	s->size = 0;
	s->capacity=capacity;
	return s;
}

void push(Stack *s, void *value){
	if(s->size >= s->capacity){
		fprintf(stderr, "Stack full, potential overflow");
		exit(EXIT_FAILURE);
	}

	s->data[s->size++] = value;
}


void print_stack(Stack *s,DisplayStack func){
	int size = s->size;

	for(int i = 0; i < size; i++){
		func(s->data[i]);
	}
}

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
