#include <stdio.h>

#define LINELENGTH 20

/* printinitchararray.c - declares a character array of 'LINELENGTH'
 * elements, and then prints the content of the array before the array
 * is initialized
int main()
{
	char line[LINELENGTH];		//declare a char array of 'LINELENGTH' elements
	
	printf("%s\n", line);		//print contents of line[]
	
	return 0;
}
