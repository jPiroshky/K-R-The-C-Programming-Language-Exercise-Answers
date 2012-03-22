#include <stdio.h>

/* fastintrange.c - a fast algorithm for directly computing limits of
 * basic integer data types 
 * 
 * Purpose: To find a method faster than adding one to compute the
 * integer ranges.  Especially the unsigned long long, which is 64 bit 
 * on my machine and has never finished using the incremental method ^_^
 * I am also hope these kinds of ideas will be applicable to computing
 * the floating point ranges as well.
 * 
 * Conclusion: This method is very fast, and takes advantage of the way
 * the machine represents these numbers to itself.  In fact, I learned
 * a lot about manipulating numbers in various bases. */
int main()
{
	unsigned long long test, max;
	int numbits;
	
	//while there is a one in the (x2)'s place
	//continue the calculation
	test = max = numbits = 1;
	while ((test=max*2)!=0)
	{
		max = test;
		++numbits;
		printf("%llu\n", max);
	}
	
	//fill in largest value and print
	max = (max-1)*2 + 1;
	printf("%llu\nnumber of bits: %d\n", max, numbits);	

	return 0;
}
