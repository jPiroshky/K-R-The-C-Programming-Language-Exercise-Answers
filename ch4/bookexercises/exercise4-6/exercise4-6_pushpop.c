#include <stdio.h>
#include "exercise4-6_globals.h"

#define MAXVAL	100  /* maximum depth of val stack */

int sp = 0;	         /* depth of val stack (next written index) */
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

/* prnt() - print the stack from bottom to top*/
void prnt()
{
	int i;
	
	printf("values on stack: ");
	for (i = 0; i < sp; i++)
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

/* swap() - swap the top two elements of the stack */
void swap()
{
	double temp;
	if (sp > 2)
	{
		temp = val[sp-1];
		val[sp-1] = val[sp-2];
		val[sp-2] = temp;
	}
	else
		printf("error: there are less than two values on the stack\n");
}

/* clear() - clears the stack */
void clear()
{
	sp = 0;
	printf("stack cleared\n");
}
