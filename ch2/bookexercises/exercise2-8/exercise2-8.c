#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000 /* maximum line input length */

unsigned rightrot(unsigned x, int n);
int numuintbits();

/* exercise2-8 - Write a function rightrot(x,n) that returns the value
 * of the integer x rotated to the right by n positions. 
 * 
 * exercise2-8.c - prompts the user for values, applies invert(x,n),
 * and the prints the result.  Will not return an error if given
 * non-decimal-number input. 
 * 
 * NOTES:
 * This program does not need to assume the word lenght of an integer
 * on the executing system due to a runtime test that costs a variable
 * and a loop, which could use a better solution.  This program
 * inspired the programs rshiftwordlengthtest.c and bitwiseintrange.c. */
int main()
{
	char numstring[MAXLINE];
	
    unsigned x;
    int n;

	//prompt user for x (number to transform)
	printf("enter a number to which to apply rightrot(x, n): ");
	gets(numstring);
	x = (unsigned) atoi(numstring);
	
	//prompt user for n (number of positions)
	printf("enter a number n corresponding to number of positions: ");
	gets(numstring);
	n = atoi(numstring);
	
	//print result
	printf("\nThe resulting transformation of x is: %u\n", rightrot(x, n));
	
	return 0;
}

unsigned rightrot(unsigned x, int n)
{
	/* create a layer with x rightshifted into place, and then turn on
	 * bits from a layer with the rightmost bits from x leftshifted into
	 * place */
	return (x >> n) | (x << (numuintbits()-n));
}

/* numuintbits() - performs a test to determine the number of bits in
 * an unsigned integer (UINT) on runtime, and returns that value. */
int numuintbits()
{
	unsigned int test;
	int numbits;
	
	//set all digits to 1
	test = ~0;
	
	//rightshift by one and count a bit for each test greater than 0
	for (numbits = 0; test > 0; ++numbits)
	{
		test = test >> 1;
	}
	
	return numbits;
}
