#include <ctype.h>
#include <string.h>
#include "exercise4-7_globals.h"

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
        if (!isdigit(c) && c != '.' && c != '-')
        {
            if (isalpha(c))          /* collect symbol */
            {
                while (!isspace(s[++i] = c = getch()))
                        ;
                s[i] = '\0';
                ungetch(c);
                return SYMBOL;
            }
            else
                return c;              /* an operator, not a symbol, number or a '-' sign/op */
        }           
        
        /* if '-', yeild operator, negative number, or error */
        if (c == '-' && isspace(c = getch()))    /* get new char into c */
        {
                ungetch(c);
                return '-';          /* a subtraction operator */
        }
        else if (s[0] == '-' && (isdigit(c) || c == '.'))
        {
                s[1] = c;           /* a negative number */
                i = 1;
        }
        else
        {
			strcpy(s, "error: only a number may be negative, not a symbol or operator\n");
			return ERROR;
		}
		
        if (isdigit(c))          /* collect integer part */
                while (isdigit(s[++i] = c = getch()))
                        ;
        if (c == '.')
                while (isdigit(s[++i] = c = getch()))
                        ;
        s[i] = '\0';
        if (c != EOF)
                ungetch(c);
        
        return NUMBER;
}
