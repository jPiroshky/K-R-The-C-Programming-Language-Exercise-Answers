#include <stdio.h>

#define MAXLINE 1000	/* maximum input line length */

void reversestring(char linein[], char lineout[]);
int ngetline(char line[], int maxline);

/* exercise1-19 - Write a function reverse(s) that reverses the
 * character string s.  Use it to write a program that reverses its
 * input a line at a time. */
int main()
{
	char linein[MAXLINE];
	char lineout[MAXLINE];
	
	int length, isnewline;
	
	//while there are new lines
	while ((length=ngetline(linein, MAXLINE)) > 0)
	{
		//remove newline from end if present
		isnewline = 0;
		if (linein[length-1]=='\n')
		{
			isnewline = 1;
			linein[length-1] = '\0';
		}
		
		//reverse line
		reversestring(linein, lineout);
		
		//add nullchar and newline if present
		if (isnewline)
		{
			lineout[length-1] = '\n';
		}
		lineout[length] = '\0';
		
		//print lineout[]
		printf("%s", lineout);
	}
	
	return 0;
}


/* reverseline() - take a string linein[], and reverse it's nonnull
 * content and output to lineout[].  Assume lineout[] is big enough. */
void reversestring(char linein[], char lineout[])
{
	int cursor, lastnonnull;
	
	//traverse forward through linein[] until nullchar.
	//cursor now holds index of nullchar
	for (cursor = 0; linein[cursor] != '\0'; ++cursor)
	{
		;
	}
	
	//lastnonnull holds index of last nonnull char
	lastnonnull = cursor-1;
	
	//traverse backwards through linein[] and copy in reverse to lineout[]
	while (cursor >= 0)
	{
		lineout[lastnonnull-cursor] = linein[cursor];
		--cursor;
	}
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
