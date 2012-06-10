#include <stdio.h>
#include "exercise4-4_globals.h"

#define MAXVAL	100  /* maximum depth of val stack */

int sp = 0;	     /* maximum depth of val stack */
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

/* prnt() - print the stack from last */
void prnt()
{
	int i;
	
	printf("values on stack: ");
	for (i = sp - 1; i >= 0; i--)
	{
		printf("%g ", val[i]);
	}
	printf("\n");
}

/* duplicate() - duplicate the stack */
void duplicate()
{
	int i;
	
	for (i = 0; i < sp; i++)
	{
		val[i + sp] = val[i];
	}
	
	sp *= 2;
}
