#include <stdio.h>
#include <float.h>

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
	//print values from float.h
	printf("from float.h:\n");
	printf("FLT_RADIX\t%d\n", FLT_RADIX);
	printf("FLT_MANT_DIG\t%d\n", FLT_MANT_DIG);
	printf("DBL_MANT_DIG\t%d\n", DBL_MANT_DIG);
	printf("LDBL_MANT_DIG\t%d\n", LDBL_MANT_DIG);
	printf("FLT_DIG\t%d\n", FLT_DIG);
	printf("DBL_DIG\t%d\n", DBL_DIG);
	printf("LDBL_DIG\t%d\n", LDBL_DIG);
	printf("FLT_MIN_EXP\t%d\n", FLT_MIN_EXP);
	printf("DBL_MIN_EXP\t%d\n", DBL_MIN_EXP);
	printf("LDBL_MIN_EXP\t%d\n", LDBL_MIN_EXP);
	printf("FLT_MIN_10_EXP\t%d\n", FLT_MIN_10_EXP);
	printf("DBL_MIN_10_EXP\t%d\n", DBL_MIN_10_EXP);
	printf("LDBL_MIN_10_EXP\t%d\n", LDBL_MIN_10_EXP);
	printf("FLT_MAX_EXP\t%d\n", FLT_MAX_EXP);
	printf("DBL_MAX_EXP\t%d\n", DBL_MAX_EXP);
	printf("LDBL_MAX_EXP\t%d\n", LDBL_MAX_EXP);
	printf("FLT_MAX_10_EXP\t%d\n", FLT_MAX_10_EXP);
	printf("DBL_MAX_10_EXP\t%d\n", DBL_MAX_10_EXP);
	printf("LDBL_MAX_10_EXP\t%d\n", LDBL_MAX_10_EXP);
	printf("FLT_MAX\t%f\n", FLT_MAX);
	printf("DBL_MAX\t%f\n", DBL_MAX);
	printf("LDBL_MAX\t%Lf\n", LDBL_MAX);
	printf("FLT_EPSILON\t%f\n", FLT_EPSILON);
	printf("DBL_EPSILON\t%f\n", DBL_EPSILON);
	printf("LDBL_EPSILON\t%Lf\n", LDBL_EPSILON);
	printf("FLT_MIN\t%f\n", FLT_MIN);
	printf("DBL_MIN\t%f\n", DBL_MIN);
	printf("LDBL_MIN\t%Lf\n", LDBL_MIN);
	printf("FLT_ROUNDS\t%d\n", FLT_ROUNDS);
	
	//if c99
//	printf("FLT_EVAL_METHOD\t%d\n", FLT_EVAL_METHOD);
//	printf("DECIMAL_DIG\t%d\n", DECIMAL_DIG);
//	printf("\t%d\n", );
	
	
	
	
	
	
	
	
	
	
	
	
	//print values from computation
	printf("\nfrom computation:\n");
	
	return 0;
}
