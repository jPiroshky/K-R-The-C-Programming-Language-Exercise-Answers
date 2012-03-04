#include <stdio.h>

/* exercise1-6 - Verify that the expression getchar() != EOF is 0 or 1.
 * 
 * exercise1-6.c - an infinite loop that takes characters from the std.
 * input and prints a 0 for an EOF character, and 1 for every other 
 * character.  
 * Note: Must use ^c or kill to terminate */
main()
{
	int result;
	
	while (1) {
		result = (getchar() != EOF);
		printf("%d", result);
	}
}
