#include <stdio.h>
#include <string.h>
#include "exercise4-7_globals.h"

#define BUFSIZE 100

char buf[BUFSIZE];   /* bufer for ungetch */
int bufp = 0;	     /* next free position in buf */

int getch(void)      /* get a (possibly pushed-back) character */
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

void ungets(char s[])
{
	int i;
	
	for (i = strlen(s)-1; i >= 0; i--)
		ungetch(s[i]);
}
