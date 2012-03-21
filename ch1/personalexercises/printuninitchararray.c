#include <stdio.h>

#define LINELENGTH 20

/* printinitchararray.c - declares a character array of 'LINELENGTH'
 * elements, and then prints the content of the array before the array
 * is initialized
 * 
 * Purpose: To see the contents of an unitialized character array.
 * 
 * Conclusion: The array prints what is stored in the memory before the
 * program is run, and so can be different every time the program is
 * run. */
int main()
{
	char line[LINELENGTH];		//declare a char array of 'LINELENGTH' elements
	
	printf("%s\n", line);		//print contents of line[]
	
	return 0;
}
