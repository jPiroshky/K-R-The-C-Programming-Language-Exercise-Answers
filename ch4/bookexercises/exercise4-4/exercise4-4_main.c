#include <stdio.h>
#include <stdlib.h>  /* for atof() */
#include "exercise4-4_globals.h"

#define MAXOP 100  /* max size of operand or operator */

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main()
{
	int type;
	double op2;
	char s[MAXOP];
	int ispop;     /* when 0, the last elemnt will not be popped upon newline */
	
	ispop = 1;
	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push((long) pop() % (long) op2);
				else
					printf("error: zero divisor\n");
				break;
			case '\n':
				if (ispop = 1)
				{
					printf("\t%.8g\n", pop());
				}
				ispop = 1;
				break;
			case SYMBOL:
				if (strcmp(s, "print") == 0)
				{
					prnt();
					ispop = 0;
				}
				else if (strcmp(s, "duplicate") == 0)
				{
					duplicate();
					ispop = 0;
				}
				else
				{
					printf("unknown command %s\n", s);
				}
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	
	return 0;
}
