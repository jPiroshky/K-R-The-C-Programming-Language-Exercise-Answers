#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000 /* maximum input line length */

void newitoa(unsigned int n, char s[], int fieldwidth);
void newreverse(char s[]);

/* exercise3-4 - In a two's complement number representation, our
 * version of itoa does not handle the largest negative number, that is,
 * the value of n equal to -(2^(wordsize-1)).  Explain why not.  Modify
 * it to print that value correctly, regardless of the machine on which
 * it runs. 
 * 
 * exercise3-4.c - implements the modified itoa() as outlined in
 * exercise3-6.  Pads with ' ' on the left until fieldwidth is reached.
 * */
int main()
{
	char line[MAXLINE];
	int x, fieldwidth;
	
	printf("enter a number to transform with itoa():\n");
	gets(line);
	x = atoi(line);
	printf("enter a minimum field width to which to pad with ' ' on the left:\n");
	gets(line);
	fieldwidth = atoi(line);
	newitoa(x, line, fieldwidth);
	printf("%s\n", line);
	
	return 0;
}

/* newitoa() - implements the modified itoa() as outlined in
 * exercise3-6.  Pads with ' ' on the left until fieldwidth is reached.
 */
void newitoa(unsigned int n, char s[], int fieldwidth)
{
	int i, sign;
		
	if ((sign = n) < 0)   /* record sign */
		n = (~n & (((unsigned int) ~0) >> 1)) + 1; /* make n positive: invert n, turn off leftmost bit, add one */
	
	i = 0;
	do {      /* generate digits in reverse order */
		s[i++] = n % 10 + '0';  /* get next digit */
	} while ((n /= 10) > 0);    /* delete it */
	if (sign < 0)
		s[i++] = '-';
	for (fieldwidth -= i; fieldwidth > 0; fieldwidth--)
		s[i++] = ' ';
	s[i] = '\0';
	newreverse(s);
}

/* reverse: reverse string s in place */
void newreverse(char s[])
{
	int c, i, j;
	
	for (i = 0, j = strlen(s)-1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
