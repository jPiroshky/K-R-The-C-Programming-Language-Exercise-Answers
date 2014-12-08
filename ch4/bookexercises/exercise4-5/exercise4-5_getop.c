#include <ctype.h>
#include "exercise4-5_globals.h"

#define EOF -1

int getch(void);
void ungetch();

/* getop: get next character on numeric operand */
int getop(char s[])
{
	int i, c;
	
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;
	if (isalpha(c))
	{
		while(isalpha(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if (c != EOF)
			ungetch(c);
		return COMMND;       /* a worded operator, i.e. a command */
	}
	if (!isdigit(c) && c != '.' && c != '-')
		return c;            /* not a number or '-' sign/op */
	if (c == '-' && isspace(c = getch()))    /* !got new char into c here! */
	{
		ungetch(c);
		return '-';          /* a subtraction operator */
	}
		else if (s[0] == '-')
		{
			s[1] = c;        /* a negative number */
			i = 1;
		}
	if (isdigit(c))          /* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))  /* collect fractional part */
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	
	return NUMBER;
}
