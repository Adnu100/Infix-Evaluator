#include <stdio.h>
#include "infixevaluator.h"

int main() {
	//comment added
	printf("Welcome! Type an expression to solve or just press enter to close.\n");
	char line[150];
	float x;
	while(getmyline(line)) {
		x = infixeval(line);
		if(x != ERROR_IN_EXPRESSION) {
			if(!(x - (int)x))
				printf("%d\n", (int)x);
			else	
				printf("%f\n", x);
		}		
		else 
			printf("Error in expression!\n");
	}
	printf("Bye!\n");
	return 0;
}
	
