#include <stdio.h>
#include "stack.h"

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

void* pop(Stack *s) {
	if (s->size == 0) {
		printf("Can't pop from empty stack");
		exit(EXIT_FAILURE);
	}

	return s->data[--s->size];
}


void print_stack(Stack *s,DisplayStack func){
	int size = s->size;

	for(int i = 0; i < size; i++){
		func(s->data[i]);
	}
}
