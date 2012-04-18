#include <stdio.h>

#define MAXLINE 1000 /* maximum line input length */

int lower(int c);

/* exercise2-10 - Rewrite the function lower, which converts upper case
 * letter to lower case, with a conditional expression instead of
 * if-else. 
 * 
 * exercise2-10.c - prompts user for text to make lower case, and
 * prints as lower case, character by character.  Implements a modified
 * lower() as per exercise2-10 instructions. */
int main(void)
{
	int c;
		
	//prompt user for text input to make lower-case
	printf("enter a text to make lower-case: \n");
	
	//while there is another character to read, apply lower() and print
	while ((c = getchar()) != EOF)
	{
		putchar(lower(c));
	}
	
	return 0;
}

/* int lower() - convert c to lower case; ASCII only.  Modified to use
 * ternary operator as per exercise2-10 instructions. */
int lower(int c)
{
	//if c is between 'A' and 'Z', make lower case, else return c 
	return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}
