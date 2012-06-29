#include <stdio.h>
#include <math.h>    /* for math and trig functions */
#include <stdlib.h>  /* for atof() */
#include <string.h>  /* for strcmp() */
#include "exercise4-7_globals.h"

#define MAXOP 100  /* max size of operand or operator */

/* from getop.c */
int getop(char []);
/* from pushpop.c */
void push(double);
double pop(void);
void prnt();
void duplicate();
void clear();
void swap();
/* from var.c */
int getvarindex(char s[]);
double getvar(int varindex);
void setvar(char s[], double value);
void delvar(char s[]);

/* exercise4-7 - Write a routine ungets(s) that will push back an entire
 * string onto the input.  Should ungets know about buf and bufp, or
 * should it just use ungetch?
 * 
 * exercise4-7_main.c - reverse Polish calculator */
int main()
{
	int type;
	double op1, op2;
	double ans;    /* most recently printed value */
	char s[MAXOP];
	int ispop;     /* when 0, a value from the stack will not be popped upon newline */
	int varindex;  /* index of variable name and value for variable operations */
	int i;
	
	ispop = 1;
	
	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case ERROR:
				printf("%s", s);
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
					printf("\t%.8g\n", (ans = pop()));
				}
				break;
			case SYMBOL:
				/* stack commands */
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
				else if (strcmp(s, "ans") == 0)
				{
					push(ans);
				}
				/* set variable */
				else if (strncmp(s, "assignto:", 9) == 0)
				{
					for (i = 0; s[i+9] != '\0'; i++)
						s[i] = s[i+9];
					s[i] = '\0';
					if (strcmp(s, "") != 0)
						setvar(s, pop());
					else
						printf("error: cannot assign variable with no variable name\n");
				}
				else if (strncmp(s, "delvar:", 7) == 0)
				{
					for (i = 0; s[i+7] != '\0'; i++)
						s[i] = s[i+7];
					s[i] = '\0';
					delvar(s);
				}
				/* variable recall and default */
				else
				{
					if ((varindex = getvarindex(s)) >= 0)
						push(getvar(varindex));
					else
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
