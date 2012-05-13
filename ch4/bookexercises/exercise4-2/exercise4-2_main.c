#include <stdio.h>

#define MAXLINE 100  /* maximum input line length */

/* Exercise 4-2.  Extend atof to handle scientific notation of the form
 * 123.45e-6, where a floating-point number may be followed by e or E
 * and an optionally signed exponent.
 * 
 * exercise4-2_main.c - rudimentary calculator.  Implements the modified
 * atof() (natof()) outlined in exercise4-2.
 * 
 * Other Project Files:
 * exercise4-2_natof.c - a function natof().  Convert string s to
 * double.  This natof is modified to extend atof to handle scientific
 * notation of the form 123.45e-6, where a floating-point number may be
 * followed by e or E and an optionally signed exponent, as per
 * exercise4-2. 
 * 
 * exercise4-2_ngetline.c - a function ngetline().  Get line into s,
 * return length */
int main(void)
{
	double sum, natof(char []);
	char line[MAXLINE];
	int ngetline(char line[], int max);
	
	sum = 0;
	while (ngetline(line, MAXLINE) > 0)
		printf("\t%g\n", sum += natof(line));
	
	return 0;
}
