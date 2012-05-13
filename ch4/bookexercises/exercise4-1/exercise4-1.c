#include <stdio.h>

#define MAXLINE 100 /* maximum input line length */

int strindex(char source[], char searchfor[]);
int ngetline(char line[], int max);

char pattern[] = "ould";  /* pattern to search for */

/* exercise4-1 - Write the function strindex(s,t) which returns the
 * position of the rightmost occurrence of t in s, or -1 if there is
 * none. 
 * 
 * exercise4-1.c - find all lines matching pattern.  This program
 * implements the modified strindex() outlined in exercise4-1. */
int main(void)
{
	char line[MAXLINE];
	int found = 0, index;
	
	while (ngetline(line, MAXLINE) > 0 )
		if((index = strindex(line, pattern)) >= 0)
		{
			printf("%srightmost index of match (above): %d\n", line, index);
			found++;
		}
		
	return found;
}

/* strindex() - returns the position of the rightmost occurrence of t in
 * s, or -1 if there is none */
int strindex(char s[], char t[])
{
	int i, j, k;
	
	for (i = 0; s[i] != '\0'; i++)
	{
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i + k - 1;
	}
	
	return -1;
}

/* getline() - get line into s, return length */
int ngetline(char s[], int lim)
{
	int c, i;
	
	i=0;
	while (--lim >0 && (c=getchar()) != EOF && c!= '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	
	return i;

}
