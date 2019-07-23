#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* functions for stack */

void init(stack *s) {
	*s = NULL;
}

void push(stack *s, float no) {
	node *tmp = (node *)malloc(sizeof(node));
	tmp->val = no;;
	tmp->next = *s;
	*s = tmp;
}

float pop(stack *s) {
	node *tmp = *s;
	float val = (*s)->val;
	(*s) = (*s)->next;
	free(tmp);
	return val;
}

int isempty(stack *s) {
	return ((*s) == NULL);
}

int isfull(stack *s) {
	return 0;
}

/* functions for cstack */

void cinit(cstack *s) {
	*s = NULL;
}

void cpush(cstack *s, char character) {
	cnode *tmp = (cnode *)malloc(sizeof(cnode));
	tmp->ch = character;
	tmp->next = *s;
	*s = tmp;
}

char cpop(cstack *s) {
	cnode *tmp = *s;
	char character = (*s)->ch;
	(*s) = (*s)->next;
	free(tmp);
	return character;
}

int cisempty(cstack *s) {
	return ((*s) == NULL);
}

int cisfull(cstack *s) {
	return 0;
}
