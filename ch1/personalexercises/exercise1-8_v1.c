#include <stdio.h>

/* exercise1-8 - Write a program to count blanks, tabs, and newlines.
 * 
 * exercise1-8.c - Reads from std. input, copies input to output, and
 * then counts blanks, tabs, and newlines */
main()
{
	int c, blanks, tabs, nls;
	
	blanks = 0;
	tabs = 0;
	nls = 0;
	
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++blanks;
		if (c == '\t')
			++tabs;
		if (c == '\n')
			++nls;
	putchar(c);
	}
	
	printf("in the input text, there were\n%3d blanks,\n%3d tabs, and\n%3d newlines\n", blanks, tabs, nls);
}
