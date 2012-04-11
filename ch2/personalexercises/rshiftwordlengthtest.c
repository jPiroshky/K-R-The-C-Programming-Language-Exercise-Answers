#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000 /* maximum line input length */

int numuintbits(void);

/* rshiftwordlengthtest.c - a program that implements numuintbits(), a
 * function that returns the number of bits in an unsigned int 
 * 
 * Purpose:
 * to find a way to find a way not to assume the word length of an
 * integer in function rightrot(x, n) in exercise2-8 
 * 
 * Conclusion:
 * I haven't yet found a way to find the number of bits in an integer
 * at runtime that doesen't involve a test variable and a loop, but the
 * solution demonstrated by this program is very simple and efficient, 
 * though it uses a variable and loop.  This program also inspires a
 * more efficient method to find the range of integer types than I 
 * proposed in fastintrange.c */
int main()
{
	printf("%d\n", numuintbits());
	
	return 0;
}

/* numuintbits() - performs a test to determine the number of bits in
 * an unsigned integer (UINT) on runtime, and returns that value. */
int numuintbits(void)
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
