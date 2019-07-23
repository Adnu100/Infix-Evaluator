eval: main.o infixevaluator.o stack.o
	cc main.o infixevaluator.o stack.o -o eval
main.o: main.c infixevaluator.h stack.h
	cc main.c -c -Wall
infixevaluator.o: infixevaluator.c infixevaluator.h stack.h
	cc infixevaluator.c -c -Wall
stack.o: stack.c stack.h
	cc stack.c -c -Wall
clean:
	rm *.o *~ -f
