#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000 /* maximum input line length */

void newitoa(unsigned int n, char s[]);
void newreverse(char s[]);

/* exercise3-4 - In a two's complement number representation, our
 * version of itoa does not handle the largest negative number, that is,
 * the value of n equal to -(2^(wordsize-1)).  Explain why not.  Modify
 * it to print that value correctly, regardless of the machine on which
 * it runs. 
 * 
 * exercise3-4.c - implements the modified itoa() as outlined in
 * exercise3-4.  Will correctly handle the largest negative number
 * by using bitwise manipulation. 
 * 
 * Explanation:
 * The textbook version of itoa() does not handle the largest negative 
 * number in a two's complement representation because of the truncation
 * that occurs when you set n = -n.  If n is a negative number, its
 * leftmost bit, the sign bit, is turned on, and the rest of the bits
 * are all inverted and one less from what they would be in their
 * positive representation.  Therefore, a statement like n = -n will
 * always truncate the largest negative number, because that number (all
 * digits following the sign bit set to one), if one is to disregard the
 * sign bit and take the rest as representing a positive number, becomes
 * a number that is the maximum for its wordsize and one less than the
 * absolute value of the original negative n. */
int main()
{
	char line[MAXLINE];
	int x;
	
	printf("enter a number to transform with itoa():\n");
	gets(line);
	x = atoi(line);
	newitoa(x, line);
	printf("%s\n", line);
	
	return 0;
}

/* newitoa() - implements the modified itoa() as outlined in
 * exercise3-4.  Will correctly handle the largest negative number
 * by using bitwise manipulation. */
void newitoa(unsigned int n, char s[])
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
