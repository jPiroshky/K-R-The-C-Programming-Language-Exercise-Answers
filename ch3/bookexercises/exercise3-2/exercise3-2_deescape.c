#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

void deescape(char s[], char t[]);
int ngetline(char s[], int lim);

/* exercise3-2 - Write a function escape(s,t) that converts characters
 * like newline and tab into visible escape sequences like \n and \t as
 * it copies the string t to s.  Use a switch.  Write a function for the
 * other direction as well, converting escape sequences into the real
 * characters.
 * 
 * exercise3-2_deescape.c - implements the escape() function in the
 * other direction as outlined in exercise3-2; the name of the created
 * function is deescape().
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
		deescape(linein, lineout);
		printf("%s", lineout);
	}	
	return 0;
}

/* deescape() - converts expanded escape sequences back to their control
 * characters.  Assume char t[] is big enough, and that s[] ends with a 
 * nullchar. */
void deescape(char s[], char t[])
{
	int incursor, outcursor;	

	outcursor = 0;
	
	for (incursor = 0; s[incursor] != '\0'; ++incursor)
	{
		if (s[incursor] == '\\') /* if current character is a backslash... */
		{
			switch (s[incursor+1]) /* ...switch the next character */
			{
				case 'a':
					t[outcursor++] = '\a';
					break;
				case 'b':
					t[outcursor++] = '\b';
					break;
				case 'f':
					t[outcursor++] = '\f';
					break;
				case 'n':
					t[outcursor++] = '\n';
					break;
				case 'r':
					t[outcursor++] = '\r';
					break;
				case 't':
					t[outcursor++] = '\t';
					break;
				case 'v':
					t[outcursor++] = '\v';
					break;
				case '\\':
					t[outcursor++] = '\\';
					break;
				case '?':
					t[outcursor++] = '\?';
					break;
				case '\'':
					t[outcursor++] = '\'';
					break;
				case '\"':
					t[outcursor++] = '\"';
					break;
				default:    /* if no match, print backslash and next char */
					t[outcursor++] = s[incursor];
					t[outcursor++] = s[incursor+1];
					break;
			}
			incursor++; /* at end of if, increment incursor past backslash character */
		}
		else  /* else, if current character is not a backslash */
		{
			t[outcursor++] = s[incursor];
		}
	}
	t[outcursor] = '\0'; /* add nullchar */
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

