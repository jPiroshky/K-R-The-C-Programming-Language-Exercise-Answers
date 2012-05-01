#include <stdio.h>
#include <string.h>

#define MAXLINE 1000 /* maximum input line length */

void escape(char s[], char t[]);

/* exercise3-2 - Write a function escape(s,t) that converts characters
 * like newline and tab into visible escape sequences like \n and \t as
 * it copies the string t to s.  Use a switch.  Write a function for the
 * other direction as well, converting escape sequences into the real
 * characters.
 * 
 * exercise3-2.c -  */
int main()
{
	char linein[MAXLINE], lineout[MAXLINE];
	
	gets(linein);
	escape(linein, lineout);
	printf("%s\n", lineout);
	
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
			case '\b':
				t[outcursor++] = '\\';
				t[outcursor++] = 'b';
			case '\f':
				t[outcursor++] = '\\';
				t[outcursor++] = 'f';
			case '\n':
				t[outcursor++] = '\\';
				t[outcursor++] = 'n';
			case '\r':
				t[outcursor++] = '\\';
				t[outcursor++] = 'r';
			case '\t':
				t[outcursor++] = '\\';
				t[outcursor++] = 't';
			case '\v':
				t[outcursor++] = '\\';
				t[outcursor++] = 'v';
			default:
				t[outcursor++] = s[incursor];
				break;
		}
	}
	t[outcursor] = '\0';
}
