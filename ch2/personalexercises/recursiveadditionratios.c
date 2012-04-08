#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000  /* maximum input line length */

/* recursiveadditionratios.c - a simple program that asks the user for
 * two initial values, and creates a recursively additive sequence where 
 * each term in the series is the sum of the two terms that preceeded
 * it, like the Fibonacci and Lucas sequences.  For each term in the 
 * created series, the index is printed, along with the previous two
 * terms, and the ratio of those two numbers.  This program is suitable
 * for demonstrating the convergence of the ratios between successive 
 * terms in a recursively additive sequence, and the speed at which this
 * convergence occurs.  To create the Fibonacci sequence enter 1 and then
 * 1 as the initial terms, and to create the Lucas sequence enter 3 and
 * then 1. */
int main()
{
	long long unsigned int a, b, c;
	int i;
	char numstring[MAXLINE];
	
	//prompt user for first number
	printf("enter a number: ");
	gets(numstring);
	a = atoi(numstring);
	
	//prompt user for second number
	printf("enter another number: ");
	gets(numstring);
	b = atoi(numstring);
	
	//for 100 terms...	
	for (i=0; i<100; ++i)
	{
		c = a + b;
		//print the index, the two preceeding terms, and the ratio
		printf("%2d %20llu %20llu %0.30Lf\n", i, a, b, (long double) a/b);
		a = b;
		b = c;
	}
	
	return 0;
}
