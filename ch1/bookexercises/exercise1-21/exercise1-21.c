#include <stdio.h>

#define MAXLINE 1000
#define TABSTOPS 8

int getnline(char s[], int maxlinesize);
void entab(char in[], char out[]);

/* exercise1-21 - Write a program entab that replaces strings of blanks
 * by the minimum number of tabs and blanks to achieve the same spacing.
 * Use the same tab stops as for detab.  When either a tab or a single
 * blank would suffice to reach a tab stop, which should be given
 * preference?
 * 
 * exercise1-21.c - a program that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing.  Tab
 * stops are given by parameter TABSTOPS.  If only one space is seen
 * before a tab stop, then a space will be added to the output instead
 * of a tab. */
int main()
{
	char linein[MAXLINE];
	char lineout[MAXLINE];
	
	while (getnline(linein, MAXLINE) > 0) {
		entab(linein, lineout);
		printf("%s", lineout);
	}
	
	return 0;
}

/* entab() - a function that takes a string and replaces strings of
 * blanks by the minimum number of tabs and blanks to achieve the same
 * spacing in the output string.  Tab stops are given by parameter
 * TABSTOPS.  If only one space is seen before a tab stop, then a space
 * will be added to the output instead of a tab. */
void entab(char in[], char out[])
{
	int incursor, outcursor, sloshcursor;
	int ismore, istab;
	int numspaces, col;
	char slosh[TABSTOPS];
	
	ismore = 1;
	col = 0;
	outcursor = 0;
	
	while (ismore == 1)
	{
		/* fill slosh */
		incursor = col*TABSTOPS;
		sloshcursor = 0;
		while (in[incursor] != '\0' && sloshcursor < TABSTOPS) {
			slosh[sloshcursor] = in[incursor];
			++incursor;
			++sloshcursor;
			if (in[incursor] == '\0') {		/* if end-of-line */
				ismore = 0;
				istab = 0;
				slosh[sloshcursor] = '\0';
			}
		}
		
		/* test slosh */
		numspaces = 0;
		sloshcursor = TABSTOPS-1;
		while (0 <= sloshcursor && ismore) {
			if (slosh[sloshcursor] == ' ') {
				++numspaces;
				--sloshcursor;
			}
			else
				break;
		}
		if (numspaces > 1)
			istab = 1;
		else
			istab = 0;
		
		/* write slosh */
		sloshcursor = 0;
		if (ismore && istab) {
			while (sloshcursor < TABSTOPS-numspaces) {
				out[outcursor] = slosh[sloshcursor];
				++sloshcursor;
				++outcursor;
			}
			out[outcursor] = '\t';
			++outcursor;
		}
		else
			while (sloshcursor<TABSTOPS && slosh[sloshcursor]!='\0') {
				out[outcursor] = slosh[sloshcursor];
				++outcursor;
				++sloshcursor;
			}
		++col;
	}
	out[outcursor] = '\0';
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
