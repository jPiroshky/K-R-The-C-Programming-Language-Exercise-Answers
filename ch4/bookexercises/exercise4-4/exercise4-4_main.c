#include <stdio.h>
#include <stdlib.h>  /* for atof() */
#include "exercise4-4_globals.h"

#define MAXOP 100  /* max size of operand or operator */

int getop(char []);  /* from file getop.c */
void push(double);   /* from file pushpop.c */
double pop(void);    /* from file pushpop.c */
void prnt();         /* from file pushpop.c */
void duplicate();    /* from file pushpop.c */
void swap();         /* from file pushpop.c */
void clear();        /* from file pushpop.c */

/* reverse Polish calculator */
int main()
{
	int type;
	double op2;
	char s[MAXOP];
	int ispop = 1;     /* when 0, the last elemnt will not be popped upon newline */
	
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
			case COMMND:
				if (strcmp(s, "print") == 0)
				{
					prnt();
					ispop = 0;   /* set ispop so case '\n' does not pop and print on current line */
				}
				else if (strcmp(s, "duplicate") == 0)
				{
					duplicate();
				}
				else if (strcmp(s, "swap") == 0)
				{
					swap();
				}
				else if (strcmp(s, "clear") == 0)
				{
					clear();
				}
				else
					printf("error: unknown command %s\n", s);
				break;
			case '\n':
				if (ispop)
					printf("\t%.8g\n", pop());   /* only pop and print on newline if prnt() was not called on current line */
				ispop = 1;
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	
	return 0;
}
