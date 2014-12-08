#include <stdio.h>
#include "exercise4-5_globals.h"

#define MAXVAL  100  /* maximum depth of val stack */

int sp = 0;          /* next open position on val stack */
double val[MAXVAL];  /* value stack */

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else 
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* prnt: print values on stack from bottom to top */
void prnt()
{
	int i;
	
	printf("values on stack: ");
	for (i = 0; i <= sp - 1; i++)
	{
		printf("%g ", val[i]);
	}
	printf("\n");
}

/* duplicate: duplicate top value on stack */
void duplicate()
{
	if (sp == 0)
		printf("error: stack empty, can't duplicate\n");
	else if (sp < MAXVAL)
		val[sp] = val[sp++ - 1];
	else
		printf("error: stack full, can't duplicate %g\n", val[sp - 1]);
}

/* swap: swap the top two elements on the stack */
void swap()
{
	double tempval;
	
	if (sp > 1)
	{
		tempval = val[sp - 1];
		val[sp - 1] = val[sp - 2];
		val[sp - 2] = tempval;
	}
	else
		printf("error: can't swap - not two elements on stack\n");
}

/* clear: clear the stack */
void clear()
{
	sp = 0;
}
