#include "stack.h"
#include <float.h>

#define ERROR_IN_EXPRESSION FLT_MAX

int getmyline(char *l);
float infixeval(char *l);
int bracketsolve(char *mainl);
float takenum(char *l, int *p);
char takechar(char *l, int *p);
int precedence(char ch);
char topof(cstack *ts);

