#include <stdio.h>

typedef struct node {
	float val;
	struct node *next;
} node;

typedef node *stack;

typedef struct cnode {
	char ch;
	struct cnode *next;
} cnode;

typedef struct cnode *cstack;

/* User to call init before calling other functions
 * User to check if stack is empty by isempty before calling pop
 * User to check if stack is full by isfull() before calling push
 * Same with the functions cinit, cpush, cpop, cisempty, cisfull
 */
 
void init(stack *s);
void push(stack *s, float no);
float pop(stack *s);
int isempty(stack *s);
int isfull(stack *s);

void cinit(cstack *s);
void cpush(cstack *s, char character);
char cpop(cstack *s);
int cisempty(cstack *s);
int cisfull(cstack *s);
