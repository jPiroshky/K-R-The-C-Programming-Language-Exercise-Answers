#include <string.h>
#include <stdio.h>

#define MAXVAR 100 /* maximum number of assigned variables */

char varname[MAXVAR][20];
double varval[MAXVAR];
int nextvar = 0;           /* next index to write */

int getvarindex(char s[]);

int getvarindex(char s[])
{
	int i;
	
	for (i = nextvar-1; i >= 0; i--)
	{
//		printf("testing if index %d has varname %s, answer is %d\n", i, s, strcmp(varname[i], s));
		if (strcmp(varname[i], s) == 0)
			return i;
	}
	
	return -1;
}

double getvar(int varindex)
{
	return varval[varindex];
}

void setvar(char s[], double value)
{
	if (nextvar < MAXVAR)
	{
		strcpy(varname[nextvar], s);
		varval[nextvar] = value;
//		printf ("assigned name %s and value %g to index %d\n", s, value, nextvar);
		nextvar++;
	}
	else
		printf("error: cannot assign variable, no more memory\n");
}

void delvar(char s[])
{
	int varindex;
	
	if ((varindex = getvarindex(s)) >= 0)
		strcpy(varname[varindex], "");
	else
		printf("error: cannot delete, variable name does not exist\n");
}
