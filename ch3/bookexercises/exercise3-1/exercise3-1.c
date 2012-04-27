#include <stdio.h>

#define N_BINSEARCH 2000000 /* number of elements in search array */
#define X_BINSEARCH 2 /* target value of search */

int binsearch(int x, int v[], int n);

/* exercise3-1 - Our binary search makes two tests inside the loop, when
 * one would suffice (at the price of more tests outside.)  Write a
 * version with only one test inside the loop and measure the difference
 * in run-time.
 * 
 * exercise3-1.c - this is a program that implements binsearch() with
 * the modifications outlined in the instructions for exercise3-1.
 * Included is a script (./runtimetest.sh) that will prompt the user for
 * the number of time trials to run, and then display the results for
 * both exercise3-1.c and exercise3-1_vtextbook.c in the same output. */
int main(void)
{
	int cursor, v[N_BINSEARCH], matchindex;
	
	//populate the array with consecutive even terms
	for (cursor = 0; cursor < N_BINSEARCH; ++cursor)
	{
		v[cursor] = cursor;
	}
	
	matchindex = binsearch(X_BINSEARCH, v, N_BINSEARCH);
	
	if (matchindex > 0)
	{
		printf("An index of a matching value is: %d\n", matchindex);
	}
	else
	{
		printf("No matching value was found in the search array.\n");
	}
	
	return 0;
}

/* int binsearch() - find x in v[0] <= v[1] <= ... <= v[n-1] 
 * NOTE: this binsearch() is modified as per the instructions for
 * exercise3-1 */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;
//	int iteration;
	
//	iteration = 0;
	
	low = 0;
	high = n - 1;
	//while low < high (terminates when low == high)
	while (low < high) {
//		printf("iteration: %d\n", ++iteration);
		mid = (low+high)/2;
		//if x is greater than v[mid], exclude v[mid] from the next set
		if (x > v[mid])
			low = mid + 1;
		//else include v[mid] in the lower set
		else
			high = mid;
	}
	
	//if the only v[] left is equal to x, return that index; else -1
	return (v[low] == x) ? low : -1;		
}
