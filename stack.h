#ifndef STACK_H
#define STACK_H
#include <stdlib.h>

typedef struct {
	void** data;
	size_t size;
	int capacity;
} Stack;

typedef void (*DisplayStack)(void *);

Stack* new_stack(int capacity);
void print_stack(Stack *s,DisplayStack func);
void push(Stack *s, void *value);
#endif
