#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getline1(char line[], int maxline);
void ncopy(char to[], char from[]);

/* exercise1-16 - Revise the main routine of the longest-line program so
 * it will correctly print the length of arbitrary long input lines, and
 * as much as possible of the text.
 * 
 * exercise1-16.c - print the longest line from input and print the
 * length */
int main()
{
	int len;				/* current line length */
	int max;				/* maximum length seen so far */
	char line[MAXLINE];		/* current input line */
	char longest[MAXLINE];	/* longest line saved here */
	int i;
	for (i=0; i<MAXLINE; ++i)
		line[i] = longest[i] = 0;
	
	max = len = 0;
	while ((len = getline1(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			ncopy(longest, line);
		}
	if (max > 0)	/* there was a line */
		printf("%s\nthis line %d characters long", longest, max);
	return 0;
}

/* getline: read a line into s, return length */
int getline1(char s[], int lim)
{
	int c, i;
	
	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void ncopy(char to[], char from[])
{
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
