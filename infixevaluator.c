#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "infixevaluator.h"

int getmyline(char *l) {
	char ch = '\0';
	int i = 0;
	while(ch != '\n') {
		ch = getchar();
		if(ch == -1)
			return 0;
		l[i++] = ch;
	}
	l[i - 1] = '\0';
	if(l[0] == '\0')
		return 0;
	else 
		return 1;
}	

int bracketsolve(char *mainl) {
	char sub1[50], sub2[50], bracketline[50];
	int flag = 0, i = 0, j = 0, inflag = 0;
	float val;
	while(mainl[i] != '\0') {
		if(mainl[i] == '(') {
			if(mainl[i + 1] == ')')
				return 0;
			flag++;
		}	
		i++;	
	}
	if(flag == 0)
		return 0;
	i = 0;
	while(mainl[i] != '(') {
		sub1[i] = mainl[i];
		i++;
	}
	sub1[i++] = '\0';
	while(inflag != -1 && mainl[i] != '\0') {
		if(mainl[i] == '(')
			inflag++;
		bracketline[j++] = mainl[i++];
		if(mainl[i] == ')')
			inflag--; 
	}
	bracketline[j] = '\0';
	j = 0;
	i++;
	while(mainl[i] != '\0')
		sub2[j++] = mainl[i++];
	sub2[j] = '\0';
	val = infixeval(bracketline);
	sprintf(bracketline, "%f", val);
	strcat(sub1, bracketline);
	strcat(sub1, sub2);
	strcpy(mainl, sub1);
	return 1;	
}

float infixeval(char *l) {
	int i = 0;
	float j, j1;
	char k, k1;
	stack s, temp;
	cstack cs, ctemp;
	init(&s);
	cinit(&cs);
	init(&temp);
	cinit(&ctemp);
	while(bracketsolve(l));
	while(l[i] != '\0') {
		j = takenum(l, &i);
		if(j == ERROR_IN_EXPRESSION) 
			return ERROR_IN_EXPRESSION;
		k = takechar(l, &i);
		push(&s, j);
		cpush(&cs, k);
	}
	if(l[i - 1] != ')' && l[i - 1] != ' ' && (l[i - 1] < '0' || l[i - 1] > '9'))
		return ERROR_IN_EXPRESSION;
	if(topof(&cs) == 'e')
		cpop(&cs);
	while(!cisempty(&cs)) {
		k = cpop(&cs);
		k1 = topof(&cs);
		if(precedence(k) > precedence(k1)) {
			j = pop(&s);
			j1 = pop(&s);
			switch(k) {
				case '+' :
					j = j + j1;
					break;
				case '-' : 
					j = j1 - j;
					break;
				case '*' :
					j = j * j1;
					break;
				case '/' :
					j = j1 / j;
					break;
				case '%' : 
					j = (float)((int)j1 % (int)j);
					break;
				default : 
					j = ERROR_IN_EXPRESSION;
					break;
			}
			if(j == ERROR_IN_EXPRESSION)
				return ERROR_IN_EXPRESSION;
			push(&s, j);
			while(!isempty(&temp)) {
				j = pop(&temp);
				push(&s, j);
			}
			while(!cisempty(&ctemp)) {
				k = cpop(&ctemp);
				cpush(&cs, k);
			}
		}
		else {
			cpush(&ctemp, k);
			j = pop(&s);
			push(&temp, j);
		}
	}	
	j = pop(&s);
	if(isempty(&s))
		return j;
	else
		return ERROR_IN_EXPRESSION;
	return 0;				
}

char topof(cstack *ts) {
	char top = '\0';
	if(!cisempty(ts)) {
		top = cpop(ts);
		cpush(ts, top);
	}	
	return top;
}

int precedence(char ch) {
	switch(ch) {
		case '+' : case '-' :
			return 1;
			break;
		case '*' : case '/' :
			return 2;
			break;
		case '%' :
			return 3;	
			break;
		case '\0' :
			return -1;
			break;	
		default :
			return 0;
			break;	
	}
	return -1;
}

float takenum(char *l, int *p) {	
	char linetonum[15];
	int i = 0;
	float sign = 1;
	while(l[*p] == ' ')
		*p += 1;
	if(l[*p] == '-') {
		sign = -1;
		*p += 1;
	}	
	while(l[*p] == ' ')
		*p += 1;	
	while((l[*p] <= '9' && l[*p] >= '0') || l[*p] == '.') {	
		linetonum[i++] = l[*p];
		*p += 1;
	} 
	linetonum[i] = '\0';
	if(linetonum[0] == '\0')
		return ERROR_IN_EXPRESSION;
	return (atof(linetonum) * sign);
}

char takechar(char *l, int *p) {
	char ch = '\0';
	while(1) {
		if(l[*p] == '\0')
			return 'e';	
		else if(l[*p] != ' ') {
			ch = l[*p];
			*p += 1;
			break;
		}
		*p += 1;		
	}
	return ch;
}

