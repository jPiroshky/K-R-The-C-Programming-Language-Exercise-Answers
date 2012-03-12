#include <stdio.h>

/* exercise1-9 - Write a program to copy its input to its output,
 * replacing each string of one or more blanks by a single blank.
 * 
 * exercise1-9_v1.c - Copies input to output and replace strings of
 * one or more blanks or tabs by a single blank. */
 main()
{
	int c;
	
	//while getchar() is not EOF
	while ((c = getchar()) != EOF )
	{
		if (c == ' ' || c == '\t')
		{
			while ((c = getchar()) == ' ' || c == '\t')	//while there are contiguous spaces
				;										//do nothing
			putchar(' ');	//add token space to output
		}
		putchar(c);
	}
}
