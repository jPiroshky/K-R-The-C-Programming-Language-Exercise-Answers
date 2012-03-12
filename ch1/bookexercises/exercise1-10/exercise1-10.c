#include <stdio.h>

/* exercise1-10 - Write a program to cpy its input to its output, 
 * replacing each tab by \t, each backspace by \b, and each backslash
 * by \\.  This makes tabs and backspaces visible in an unambiguous way.
 * 
 * exercise1-10.c - Replaces tabs with \t, backspaces with \b, and 
 * backslash with \\. */
main()
{
	int c;
	
	while ((c = getchar()) != EOF) {
		if (c == '\t')
			printf("\\t");
		else if (c == '\b')
			printf("\\b");
		else if (c == '\\')
			printf("\\\\");
		else
			putchar(c);
	}
}
		
