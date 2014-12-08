#include <stdio.h>
#include <stdlib.h>  /* for atof() */
#include <math.h>    /* for functions found in the COMMND section of the switch(type) */
#include "exercise4-5_globals.h"

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
	double op1, op2;
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
				/* stack commands from pushpop.c */
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
				/* math commands */
				else if (strcmp(s, "sin") == 0)
				{
					push(sin(pop()));
				}
				else if (strcmp(s, "cos") == 0)
				{
					push(cos(pop()));
				}
				else if (strcmp(s, "tan") == 0)
				{
					push(tan(pop()));
				}
				else if (strcmp(s, "exp") == 0)
				{
					push(exp(pop()));
				}
				else if (strcmp(s, "log") == 0)
				{
					push(log(pop()));
				}
				else if (strcmp(s, "pow") == 0)
				{
					op2 = pop();
					op1 = pop();
					if (op1 == 0.0 && op2 <= 0.0)
						printf("error: base is 0 and exponent is 0 or less\n");
					else if (op1 <= 0.0 && floor(op2) != op2)
						printf("error: base is less than 0 and exponent is not an integer\n");
					else
					push(pow(op1, op2));
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
