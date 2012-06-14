#include <stdio.h>
#include <stdlib.h>  /* for atof() */
#include <string.h>  /* for strcmp() */
#include "exercise4-4_globals.h"

#define MAXOP 100  /* max size of operand or operator */

int getop(char []);
void push(double);
double pop(void);
void prnt();
void duplicate();
void clear();


/* reverse Polish calculator */
int main()
{
	int type;
	double op2;
	char s[MAXOP];
	int ispop;     /* when 0, a value from the stack will not be popped upon newline */
	
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
				if (ispop == 0)
				{
					ispop = 1;
				}
				else
				{
					printf("\t%.8g\n", pop());
				}
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
				else if (strcmp(s, "swap") == 0)
				{
					swap();
					ispop = 0;
				}
				else if (strcmp(s, "clear") == 0)
				{
					clear();
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
