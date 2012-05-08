#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000 /* maximum input line length */

void newitoa(unsigned int n, char s[], int base);
void newreverse(char s[]);

/* exercise3-5 - Write the function itob(n,s,b) that converts the
 * integer n into a base b character representation in the string s.
 * In particular, itob(n,s,16) formats s as a hexadecimal integer in s.
 * 
 * exercise3-5.c - implements itob() with the modifications proposed in 
 * exercise3-5.  Prompts the user for a number to transform and a base
 * to transform it into.  Numbers larger than 9 are printed as a letter
 * [a-j] with a number of prime marks behind it.  Virtually any base can
 * be chosen, the only limit is the length of the string.  Try a fun
 * base, like 60 or 300 ^_^. */
int main()
{
	char line[MAXLINE];
	int x, base;
	
	printf("enter a number to transform with itoa():\n");
	gets(line);
	x = atoi(line);
	printf("enter a number to transform with itoa():\n");
	gets(line);
	base = atoi(line);
	newitoa(x, line, base);
	printf("%s\n", line);
	
	return 0;
}

/* newitoa() - implements the modified itoa() as outlined in
 * exercise3-5.  Numbers larger than 9 are printed as a letter
 * [a-j] with a number of prime marks behind it.  Virtually any base can
 * be chosen, the only limit is the length of the string. */
void newitoa(unsigned int n, char s[], int base)
{
	int i, j, sign;
		
	if ((sign = n) < 0)   /* record sign */
		n = (~n & (((unsigned int) ~0) >> 1)) + 1; /* make n positive: invert n, turn off leftmost bit, add one */
	
	i = 0;
	do {      /* generate digits in reverse order */
		if (n % base < 9) /* get next digit */
		{
			s[i++] = n % base + '0';
		}
		else
		{
			/* print numbers [10-19] as [a-j] and numbers > 19 as [a-j]', [a-j]'', etc... */
			for (j = (n % base) - 10; j >= 0; j -= 10)
			{
				if (j < 10)
				{
					s[i++] = j + 'a';
					break;  /* necessary for termination */
				}
				else
					s[i++] = '\'';	
			}	
		}
	} while ((n /= base) > 0);    /* delete it */
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
