#include <stdio.h>
#include <math.h>    /* for math and trig functions */
#include <stdlib.h>  /* for atof() */
#include <string.h>  /* for strcmp() */
#include "exercise4-5_globals.h"

#define MAXOP 100  /* max size of operand or operator */

int getop(char []);
void push(double);
double pop(void);
void prnt();
void duplicate();
void clear();
void swap();

/* exercise4-5 - Add access to library functions like sin, exp, and pow.
 * See <math.h> in Appendix B, Section 4. 
 * 
 * exercise4-5_main.c - reverse Polish calculator */
int main()
{
	int type;
	double op1, op2;
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
				/* stack commands */
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
				{
					printf("error: unknown symbol/command %s\n", s);
				}
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	
	return 0;
}
