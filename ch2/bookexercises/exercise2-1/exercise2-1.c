#include <stdio.h>
#include <limits.h>

/* exercise2-1.c - Write a program to determine the ranges of char,
 * short, int, and long variables, both signed and unsigned, by printing
 * appropriate values form standard headers and by direct computation.
 * Harder if you compute them: determine the ranges of the various
 * floating-point types. 
 * 
 * Credits:
 * Earlier, I didn't give proper credit for the ideas I used in this
 * program.  User Name:'s post on
 * http://cboard.cprogramming.com/c-programming/127683-computing-max-min-values-numeric-variables-ints-chars-etc.html
 * was the first method I used to approach this problem, and was very
 * important for me to get my start. */
int main(void)
{
	//print values from limits.h
	printf("from limits.h:\n");
	printf("CHAR_BIT\t%d\n", CHAR_BIT);
	printf("CHAR_MAX\t%d\n", CHAR_MAX);
	printf("CHAR_MIN\t%d\n", CHAR_MIN);
	printf("INT_MAX \t%d\n", INT_MAX);
	printf("INT_MIN \t%d\n", INT_MIN);
	printf("LONG_MAX\t%ld\n", LONG_MAX);
	printf("LONG_MIN\t%ld\n", LONG_MIN);
	printf("SCHAR_MAX\t%d\n", SCHAR_MAX);
	printf("SCHAR_MIN\t%d\n", SCHAR_MIN);
	printf("SHRT_MAX\t%d\n", SHRT_MAX);
	printf("SHRT_MIN\t%d\n", SHRT_MIN);
	printf("UCHAR_MAX\t%u\n", UCHAR_MAX);
	printf("UINT_MAX\t%u\n", UINT_MAX);
	printf("ULONG_MAX\t%lu\n", ULONG_MAX);
	printf("ULLONG_MAX\t%llu\n", ULLONG_MAX);
	printf("USHRT_MAX\t%u\n", USHRT_MAX);
	
	//print values from computation
	printf("\nfrom computation:\n");
	
	// CHAR_BIT
	int charbit;
	unsigned char maxuchar, testuchar;
	maxuchar = 0;
	for (testuchar=1; testuchar > maxuchar; ++testuchar)  // test overflows; max is the max value
		maxuchar = testuchar;
	testuchar = maxuchar;  // begin bit caluclation on variable testuchar
	for (charbit=1; testuchar > 1; ++charbit)
		testuchar = testuchar / 2;
	printf("CHAR_BIT\t%d\n", charbit);
	
	// CHAR_MAX
	char testchar, maxchar;
	maxchar = 0;
	for (testchar=1; testchar > maxchar; ++testchar)  // test overflows; max is the max value
		maxchar = testchar;
	printf("CHAR_MAX\t%d\n", (int) maxchar);
	// CHAR_MIN
	printf("CHAR_MIN\t%d\n", (int) testchar);
	
	// INT_MAX
	int maxint, testint;
	maxint = 0;
	for (testint=1; testint > maxint; ++testint)
		maxint = testint;
	printf("INT_MAX \t%d\n", maxint);
	// INT_MIN
	printf("INT_MIN \t%d\n", testint);
	
	// LONG_MAX
	long maxlong, testlong;
	maxlong = 0;
	for (testlong=1; testlong > maxlong; ++testlong)
		maxlong = testlong;
	printf("LONG_MAX\t%ld\n", maxlong);
	// LONG_MIN
	printf("LONG_MIN\t%ld\n", testlong);
	
	// SCHAR_MAX
	char maxschar, testschar;
	maxschar = 0;
	for (testschar=1; testschar > maxschar; ++testschar)
		maxschar = testschar;
	printf("SCHAR_MAX\t%d\n", (int) maxschar);
	// SCHAR_MIN
	printf("SCHAR_MIN\t%d\n", (int) testschar);
	
	// SHRT_MAX
	short maxshrt, testshrt;
	maxshrt = 0;
	for (testshrt=1; testshrt > maxshrt; ++testshrt)
		maxshrt = testshrt;
	printf("SHRT_MAX\t%d\n", maxshrt);
	// SHRT_MIN
	printf("SHRT_MIN\t%d\n", testshrt);
	
	// UCHAR_MAX
	printf("UCHAR_MAX\t%d\n", (int) maxuchar);
	
	// USHRT_MAX
	unsigned short maxushrt, testushrt;
	maxushrt = 0;
	for (testushrt=1; testushrt > maxushrt; ++testushrt)
		maxushrt = testushrt;
	printf("USHRT_MAX\t%u\n", (int) maxushrt);
	
	// UINT_MAX
	unsigned int maxuint, testuint;
	maxuint = 0;
	for (testuint=1; testuint > maxuint; ++testuint)
		maxuint = testuint;
	printf("UINT_MAX\t%u\n", maxuint);
	
	// ULONG_MAX
	unsigned long maxulong, testulong;
	maxulong = 0;
	for (testulong=1; testulong > maxulong; ++testulong)
		maxulong = testulong;
	printf("ULONG_MAX\t%lu\n", maxulong);
	
	// ULLONG_MAX
	unsigned long long maxullong, testullong;
	maxullong = 0;
	for (testullong=1; testullong > maxullong; ++testullong)
		maxullong = testullong;
	printf("ULLONG_MAX\t%llu\n", maxullong);

	return 0;
}
