#include <stdio.h>

#define MAXLINE 1000
#define TABSTOPS 4

int getnline(char out[], int maxlinesize);
void detab(char in[], char out[]);

/* exercise1-20 - Write a program detab that replaces tabs in the input
 * with the proper number of blanks to space to the next tab stop.
 * Assume a fixed set of tab stops, say every n columns.  Should n be a
 * variable or a symbolic parameter? 
 * 
 * exercise1-20.c - a program that replaces tabs with the appropriate
 * number of spaces given by TABSTOPS. */
int main()
{
	char linein[MAXLINE];
	char lineout[MAXLINE];
	
	getnline(linein, MAXLINE);
	detab(linein, lineout);
	printf("%s", lineout);
	
	return 0;
}

int getnline(char s[], int lim)
{
	int c, i;
	
	for(i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* detab() - a function takes a string, and replaces tabs with the
 * appropriate number of spaces in an output string, given by TABSTOPS.
 * */
void detab(char in[], char out[])
{
	int incurs, outcurs, col;
	
	incurs = outcurs = col = 0;
	while (in[incurs] != '\0')                       /* while not end of string */
	{
		if (in[incurs] == '\t') {                    /* if in[i] is a tab */
			for (; col <= outcurs; col=col+TABSTOPS) /* set col to the next stop */
				;
			while (outcurs < col) {                  /* while not at next stop */
				out[outcurs] = ' ';                  /* add space to out string */
				++outcurs;
			}
			++incurs;
		}
		else {                                       /* else copy character */
			out[outcurs] = in[incurs];
			++outcurs;
			++incurs;
		}
	}
	out[outcurs] = '\0';
}
