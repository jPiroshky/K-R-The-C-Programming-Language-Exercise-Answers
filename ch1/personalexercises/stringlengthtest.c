#include <stdio.h>

/* stringlengthtest.c - take a string stored in a character array, then
 * replace a character in the middle with a null character, and print
 * the result
 * 
 * Purpose:
 * to see the result of printing a string with characters after a null
 * character
 * 
 * Conclusion:
 * If a string is printed using printf("%s", string), then only
 * characters before the first null character are printed. */
 int main()
 {
	//define and print the initial string
	char line[] = "this is the string.\n";
	printf("%s", line);
	
	//edit the string
	printf("editing string...\n");
	line[8] = '\0';
	
	//print the edited string
	printf("%s", line);
	 
	return 0;
}
