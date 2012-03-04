#include <stdio.h>

/* exercise1-2 - Experiment to find out what happens when prints's
 * argument string contains \c, where c is some character not listed
 * above.
 * 
 * exercise1-2.c - print a list of escape seqences, including one
 * unknown escape sequence */
main()
{
	printf("print escape sequences, one per new line:\n");
	printf("\\a: \a\n");
	printf("\\b: \b\n");
	printf("\\f: \f\n");
	printf("\\n: \n\n");
	printf("\\r: \r\n");
	printf("\\t: \t\n");
	printf("\\v: \v\n");
	printf("\\\\: \\\n");
	printf("\\?: \?\n");
	printf("\\': \'\n");
	printf("\\\": \"\n");
	printf("\\c: \c\n");  //unknown escape sequence
}
