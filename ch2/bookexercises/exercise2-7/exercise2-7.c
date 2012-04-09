#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000  /* maximum input line length */

unsigned setbits(unsigned x, int p, int n, unsigned y);

/* exercise2-6 - Write a function setbits(x,p,n,y) that returns x with
 * the n bits that begin at position p set to the rightmost n bits of y,
 * leaving the other bits unchanged. 
 * 
 * exercise2-6.c - prompts the user for values, applies 
 * setbits(x,p,n,y), and the prints the result.  Will not return an
 * error if given non-decimal-number input. 
 * 
 * NOTE: This implementation begs a more elegant solution. */
int main()
{
        char numstring[MAXLINE];
        
        unsigned x, y;
        int p, n;
        
        //prompt user for x (number to transform)
        printf("enter a number to apply setbits(x, p, n, y) to: ");
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
        
        //prompt user for y (transformant)
        printf("enter a number y to apply the righmost n bits from: ");
        gets(numstring);
        y = (unsigned) atoi(numstring);
        
        //print result
        printf("\nThe resulting transformation of x is: %u\n", setbits(x, p, n, y));
        
        return 0;
}

/* setbits() - set the n bits of variable x starting at position p to 
 * the first n bits (rightmost n bits) of variable y. */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{       
        /* set active bits in x to 0, then apply mask with active bits in y
         * shifted into position */
        // (~(~(~0 << n) << (p+1-n))) creates a mask with 0s in the active bits of x
        // ((y & ~(~0 << n)) << (p+1-n)) rightmost n bits of y shifted into place
        return x & (~(~(~0 << n)<<(p+1-n))) | ((y & ~(~0 << n)) << (p+1-n));
}

unsigned invert(unsigned x, int p, int n)
{
    /* turn off active bits in x, and then turn on inverted active bits in x */
    return (x & (~(~(~0 << n)<<(p+1-n)))) | (~x & (~(~0 << n) << (p+1-n)));
}