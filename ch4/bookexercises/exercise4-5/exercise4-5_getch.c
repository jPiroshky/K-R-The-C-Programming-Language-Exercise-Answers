#include <stdio.h>
#include "exercise4-5_globals.h"

#define BUFSIZE 100

char buf[BUFSIZE];   /* bufer for ungetch */
int bufp = 0;	     /* next free position in buf */

int getch(void)    /* get a (possibly pushed-back) character */
{
	return (bufp > 0 ) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
