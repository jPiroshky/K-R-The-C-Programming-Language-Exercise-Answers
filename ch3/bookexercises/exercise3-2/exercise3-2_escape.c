#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

void escape(char s[], char t[]);
int ngetline(char s[], int lim);

/* exercise3-2 - Write a function escape(s,t) that converts characters
 * like newline and tab into visible escape sequences like \n and \t as
 * it copies the string t to s.  Use a switch.  Write a function for the
 * other direction as well, converting escape sequences into the real
 * characters.
 * 
 * exercise3-2_escape.c - implements the function escape() as outlined
 * in exercise3-2.  All output will be on the same line, as all newline
 * characters will be transformed into their escape sequences. 
 * 
 * NOTE: use test_escape.in found in the exercise3-2 folder to test
 * exercise3-2_escape.c, and see that all of the control characters have
 * been transformed into their escape sequences.  Then you can use the
 * resulting file to test exercise3-2_deescape.c, and verify that the
 * result of deescape() is identical to test_escape.in. */
int main()
{
	char linein[MAXLINE], lineout[MAXLINE];
	
	while (ngetline(linein, MAXLINE) > 0)
	{
		escape(linein, lineout);
		printf("%s", lineout);
	}
	
	return 0;
}

/* escape() - converts control characters to their expanded escape
 * sequences.  Assume char t[] is big enough, and that s[] ends with a 
 * nullchar. */
void escape(char s[], char t[])
{
	int incursor, outcursor;	

	outcursor = 0;
	
	for (incursor = 0; s[incursor]!='\0'; incursor++)
	{
		switch (s[incursor])
		{
			case '\a':
				t[outcursor++] = '\\';
				t[outcursor++] = 'a';
				break;
			case '\b':
				t[outcursor++] = '\\';
				t[outcursor++] = 'b';
				break;
			case '\f':
				t[outcursor++] = '\\';
				t[outcursor++] = 'f';
				break;
			case '\n':
				t[outcursor++] = '\\';
				t[outcursor++] = 'n';
				break;
			case '\r':
				t[outcursor++] = '\\';
				t[outcursor++] = 'r';
				break;
			case '\t':
				t[outcursor++] = '\\';
				t[outcursor++] = 't';
				break;
			case '\v':
				t[outcursor++] = '\\';
				t[outcursor++] = 'v';
				break;
			case '\\':
				t[outcursor++] = '\\';
				t[outcursor++] = '\\';
				break;
			case '\?':
				t[outcursor++] = '\\';
				t[outcursor++] = '?';
				break;
			case '\'':
				t[outcursor++] = '\\';
				t[outcursor++] = '\'';
				break;
			case '\"':
				t[outcursor++] = '\\';
				t[outcursor++] = '\"';
				break;
			default:
				t[outcursor++] = s[incursor];
				break;
		}
	}
	t[outcursor] = '\0';
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

