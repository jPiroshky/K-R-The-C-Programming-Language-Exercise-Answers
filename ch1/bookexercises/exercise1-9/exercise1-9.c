#include <stdio.h>

/* exercise1-9 - Write a program to copy its input to its output,
 * replacing each string of one or more blanks by a single blank.
 * 
 * exercise1-9.c - Copies input to output and replace strings of
 * one or more blanks by a single blank */
 main()
{
	int c;
	
	//while getchar() is not EOF
	while ((c = getchar()) != EOF )
	{
		if (c == ' ')
		{
			while ((c = getchar()) == ' ')	//while there are contiguous spaces
				;							//do nothing
			putchar(' ');	//add token space to output
		}
		putchar(c);
	}
}
