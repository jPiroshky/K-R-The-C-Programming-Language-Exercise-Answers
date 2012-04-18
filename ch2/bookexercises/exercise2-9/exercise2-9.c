#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000 /* maximum input line length */

int bitcount(unsigned x);

/* exercise2-9 - In a two's complement number system, x &= (x-1) deletes
 * the rightmost 1-bit in x.  Explain why.  Use this observation to
 * write a faster version of bitcount.
 * 
 * exercise2-9.c - this program implements the faster bitcount function
 * proposed in the instructions to exercise2-9.
 * 
 * Explanation:
 * The expression x &= (x-1) only and always deletes the rightmost 1-bit
 * for a number greater than 0 in a two's complement system because of
 * the way numbers 'carry' over to the next-largest place in
 * subtraction.  Subtracting one from the one's place always toggles the
 * rightmost bit of a binary number, so that when the & operator is
 * applied, we can always be sure that the rightmost bit will be
 * turned-off in the result.  Furthermore, as long as the number is odd,
 * we can be sure that only the rightmost bit will be altered in the
 * result.  If the number is even, then there is already a 0 in the
 * one's place before we subtract, and subtracting 1 from the number
 * will turn-off the 1-bit in the next-largest place that a 1-bit occurs
 * and will also turn on all the bits to the right of that place.
 * Therefore, when we apply the & operator, we can be sure that all of
 * the bits to-the-right-of and including that next-largest place will 
 * all be turned-off in the result, effectively only turning off the
 * rightmost 1-bit of the original number due to the toggling that
 * occurs between x and (x-1).  The result must also be even (because
 * its rightmost bit must be turned off).  Whether the initial number is
 * even or odd, when applying x &= (x-1), we are assured that only one
 * digit will be altered in the result, and that the alteration will
 * always be to turn that bit off. */
int main(void)
{
	char numstring[MAXLINE];
	
    unsigned x;

	//prompt user for x (number to transform)
	printf("enter a number to which to apply bitcount(x): ");
	gets(numstring);
	x = (unsigned) atoi(numstring);
	
	//print result of bitcount()
	printf("The number of 1-bits in the number is: %d\n", bitcount(x));
	
	return 0;

}
 
/* bitcount() - takes an unsigned integer x, and returns the number of
 * turned-on bits in x.  This is a faster bitcount modified to use the
 * expression proposed in exercise2-9. */
int bitcount(unsigned x)
{
	int b;
	
	for(b = 0; x != 0; x &= (x-1))
	{
		++b;
	}
	
	return b;
}
