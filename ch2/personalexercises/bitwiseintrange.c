#include <stdio.h>

/* bitwiseintrange.c - a program that uses bit operations to quickly
 * construct the maximum value of an unsigned integer, and also the
 * maximum and minimum values of an integer.  Assumes a two's
 * complement machine.
 * 
 * Purpose:
 * to find the minimum and maximum values of an integer type using few
 * steps, no loops, and without the use of the math library
 * 
 * Conclusion:
 * this is a really low cost way to determine the minimum and maximum
 * values of an integer type at runtime on a two's complement machine */
int main()
{
	//turn all bits to one and rightshift by one for the sign
	printf("INT_MAX: %d\n", (unsigned int) ~0 >> 1);
	
	//invert the previous expression
	printf("INT_MIN: %d\n", ~((unsigned int) ~0 >> 1));
	
	//turn all bits to one!
	printf("UINT_MAX: %u\n", (unsigned int) ~0);
	
	return 0;
}

