#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 1000 /* maximum input line length */

void expand(char s1[], char s2[]);
int ngetline(char s[], int lim);

/* exercise3-3 - Write a function expand(s1,s2) that expands shorthand
 * notations like a-z in the string s1 into the equivalent complete list
 * abc...xyz in s2.  Allow for letter of either case and digits, and be
 * prepared to handle cases like a-b-c and a-z0-9 and -a-z.  Arrange
 * that a leading or trailing - is taken literally. 
 * 
 * exercise3-3.c - implements the expand() function.  Ignores series of
 * '-' in the form of a-d-f-h, for example.  Does not expand characters
 * that are ordered consecutively, ex a-b, 0-1.  Will expand 0-a. 
 * 
 * NOTE:
 * This program could be modified to allow for series of expansions, as
 * in a-c-e-g-i, for example.  Currently -a-z and a-z- do not expand. */
 int main()
{
	char linein[MAXLINE], lineout[MAXLINE];
	
	while (ngetline(linein, MAXLINE) > 0)
	{
		expand(linein, lineout);
		printf("%s", lineout);
	}
	
	return 0;
}

/* expand() - expands expressions of the form (alphanum, '-', alphanum)
 * found in s1 into the full list in s2.  Ignores series of '-' in the 
 * form of a-d-f-h, for example.  Does not expand characters that are 
 * ordered consecutively, ex a-b, 0-1.  Will expand 0-a. */
void expand(char s1[], char s2[])
{
	int incursor, outcursor;
	int inseries;  /* toggle to indicate consecutive '-'s, ex. -a-, a-b-c, a-b-c-d... */
	int diff;  /* the gap between the characters in an expansion */
	
	incursor = outcursor = 0;
	inseries = 0;
	
	while (s1[incursor] != '\0')
	{
		// check for expansion expression (alphanum, '-', alphanum) and calculate diff and make sure abs(diff) > 1 
		if (s1[incursor+1]=='-' && s1[incursor+3]!='-' && !inseries && isalnum(s1[incursor]) && isalnum(s1[incursor+2]) && (fabs(diff = s1[incursor+2] - s1[incursor]) > 1))
		{
			while (diff != 0)
			{
				s2[outcursor++] = s1[incursor+2] - diff;
				diff = diff - (diff/fabs(diff));  /* decrement diff in the correct direction */
			}
			s2[outcursor++] = s1[incursor+2];
			incursor+=3;  /* increment incursor by 3, to the next expansion candidate position */
		}
		else
		{
			//series toggle: if current character is a '-', turn on the series toggle
			if (s1[incursor] == '-')
				inseries = 1;
			else
				inseries = 0;

			s2[outcursor++] = s1[incursor++];  /* write and increment */
		}
	}
	s2[outcursor] = '\0';
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
