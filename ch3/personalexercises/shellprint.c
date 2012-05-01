#include <stdio.h>

#define ARRAY_SIZE 20 /* length of array to be sorted */

/* shellprint.c - a simple program to output the result of each
 * operation of the shellsort algorithm on an array */
int main()
{
	int v[ARRAY_SIZE], cursor;
	
	//set up array
	for (cursor = 0; cursor < ARRAY_SIZE; cursor++)
	{
		v[cursor] = ARRAY_SIZE - 1 - cursor;
		printf("%2d ", v[cursor]); 
	}
	
	int gap, i, j, temp;
	
	for (gap = ARRAY_SIZE/2; gap > 0; gap /= 2)
		for (i = gap; i < ARRAY_SIZE; i++)
			for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
				//print array
				printf("\n");
				for (cursor = 0; cursor < ARRAY_SIZE; cursor++)
					printf("%2d ", v[cursor]); 	
			}
	printf("\n");
	
	return 0;		
}
