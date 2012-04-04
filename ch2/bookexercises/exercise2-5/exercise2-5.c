#include <stdio.h>

#define MAXLINE 1000 /* maximum per line length from std. input */

int any(char s1[], char s2[]);
int ngetline(char s[], int lim);

/* exercise2-5 - Write the function any(s1, s2), which returns the
 * first location in a string s1 where any character from the string s2
 * occurs, or -1 if s1 contains no characters from s2. (The standard
 * library function strpbrk does the same job but returns a pointer to
 * the location.) 
 * 
 * exercise2-5.c - prompts the user for two strings, and then prints the
 * first location in a string s1 that matches any characters in the
 * second line 
 * 
 * NOTE: when testing this program, you must use ^d with no newline
 * character to pass the second line from the terminal to the program,
 * or else you will always match the newline character in the first line
 * with the newline character from the second, and never recieve a value
 * of -1 for no match.  */
int main()
{
	char s1[MAXLINE], s2[MAXLINE], matchindex;
	
	//prompt user for a string to be analyzed
	printf("enter a line (max 1000 chars) to return an index from:\n");
	ngetline(s1, MAXLINE);
	
	//prompt user for a string to match against
	printf("enter a line (max 1000 chars) to return from the previous\n"
	"line the index of the first char that matches any char in this line:\n");
	ngetline(s2, MAXLINE);
	
	//apply analysis
	matchindex = any(s1, s2);
	
	//print result
	printf("The index of the first character in the first string to match"
	" any character from the second is:\n%d\n", matchindex);
	
	return 0;
}

/* any() - returns the first location in a string s1[] where any
 * character from the string s2 occurs, or -1 if s1[] contains no
 * characters from s2[].  Both strings must have indicies no greater
 * than the maximum value of an int.  */ 
int any(char s1[], char s2[])
{
	int cursor_s1, cursor_s2, ismatch;
	
	cursor_s1 = cursor_s2 = 0;
	
	//while there is another character to read in s1
	while (s1[cursor_s1] != '\0')
	{
		ismatch = 0;
		
		//traverse through s2 while !ismatch
		for (cursor_s2 = 0; !ismatch && (s2[cursor_s2] != '\0'); ++cursor_s2)
		{
			//and if a character matches
			if (s1[cursor_s1] == s2[cursor_s2])
			{
				ismatch = 1;
			}
		}
		
		//then return the cursor_s1 position of the match
		if (ismatch)
		{
			return cursor_s1;
		}
		//else, advance cursor_s1
		else
		{
			++cursor_s1;
		}
	}
	
	//after traversing s1, return -1 if no match
	return -1;
}

/* ngetline() - read a line into s, return length */
int ngetline(char s[], int lim)
{
	int c, i;
	
	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if(c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
