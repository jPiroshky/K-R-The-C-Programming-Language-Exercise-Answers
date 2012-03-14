#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getline1(char line[], int maxline);
void ncopy(char to[], char from[]);

/* exercise1-17 - Write a program to print all input lines that are
 * longer than 80 characters.
 * 
 * exercise1-17.c - print lines from input that are longer than 80
 * characters  */
int main()
{
	int len;				/* current line length */
	char line[MAXLINE];		/* current input line */
	int i;
	for (i=0; i<MAXLINE; ++i)
		line[i] = 0;
	
	len = 0;
	while ((len = getline1(line, MAXLINE)) > 0)
		if (len > 80) {
			printf("%s", line);
		}
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
