#include <stdio.h>

#define MAXLINE 1000	/* maximum input line length */

void deltrailblanks(char linein[], char lineout[]);
int ngetline(char line[], int maxline);

/* exercise1-18 - Write a program to remove trailing blanks and tabs
 * from each line of input, and to delete entirely blank lines.
 * 
 * exercise1-18.c - removes trailing blanks and tabs from each line of
 * input, and deletes entirely blank lines. */
int main()
{
	char linein[MAXLINE];
	char lineout[MAXLINE];
	
	//read, sanitize, and print non empty lines while there are lines
	while (ngetline(linein, MAXLINE) > 0)
	{
		deltrailblanks(linein, lineout);
		if (lineout[0]!='\n' && lineout[0]!='\0')
			printf("%s", lineout);
	}
	
	return 0;
}

/* deltrailblanks() - take a string linein[], remove spaces and tabs from
 * the end of the string, and output to lineout[].  Assume lineout[] is
 * big enough.  If newline at end of string, one newline will be
 * retained. */
void deltrailblanks(char linein[], char lineout[])
{
	int cursor, isnewline;
	
	isnewline = 0;
	
	//copy linein[] to lineout[].  cursor is at '\0' at end of string.
	cursor = 0;
	while ((lineout[cursor] = linein[cursor]) != '\0')
		++cursor;
		
	//traverse backwards through string and stop on first 'nonblank' character
	//check for newline character
	//cursor can be -1 for a 'blank only' line
	while (cursor>=0 && (lineout[cursor]==' ' || lineout[cursor]=='\t' || lineout[cursor]=='\n' || lineout[cursor]=='\0'))
	{
		if (lineout[cursor] == '\n')
			isnewline = 1;
		
		--cursor;
	}
	
	//add nullchar and newline if present
	if (isnewline) {
		++cursor;
		lineout[cursor] = '\n';
	}
	++cursor;
	lineout[cursor] = '\0';
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
