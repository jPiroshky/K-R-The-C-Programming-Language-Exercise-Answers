#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000  /* maximum input line length */

unsigned setbits(unsigned x, int p, int n, unsigned y);

/* exercise2-7 - Write a function invert(x,p,n) that returns x with the
 * n bits that begin at position p set to the rightmost n bits of y,
 * leaving the other bits unchanged.
 * 
 * exercise2-7.c - prompts the user for values, applies invert(x,p,n),
 * and the prints the result.  Will not return an error if given
 * non-decimal-number input. */
int main()
{
        char numstring[MAXLINE];
        
        unsigned x;
        int p, n;
        
        //prompt user for x (number to transform)
        printf("enter a number to apply invert(x, p, n) to: ");
        gets(numstring);
        x = (unsigned) atoi(numstring);
        
        //prompt user for p (position)
        printf("enter a number p corresponding to the position: ");
        gets(numstring);
        p = atoi(numstring);
        
        //prompt user for n (number of digits)
        printf("enter a number n corresponding to the number of digits: ");
        gets(numstring);
        n = atoi(numstring);
                
        //print result
        printf("\nThe resulting transformation of x is: %u\n", invert(x, p, n));
        
        return 0;
}

/* invert() - inverts n bits in x starting at position p (counting back
 * to origin) */
unsigned invert(unsigned x, int p, int n)
{
    /* turn off active bits in x, and then turn on inverted active bits
     * in x */
    // (x & (~(~(~0 << n)<<(p+1-n)))) turns off active bits in x
    // (~x & (~(~0 << n)<<(p+1-n))) creates layer with inverted bits in place
    return (x & (~(~(~0 << n)<<(p+1-n)))) | (~x & (~(~0 << n)<<(p+1-n)));
}
