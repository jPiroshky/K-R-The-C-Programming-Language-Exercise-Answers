#include <stdio.h>

/* exercise1-14 - Write a program to print a histogram of the
 * frequencies of different characters in its input
 * 
 * exercise1-14_v1.c - (this version prints a key with every character
 * in the set from 0 to 127) prints a histogram of the frequencies of the
 * characters given as input.  Prints with histogram bars horizontal
 * for ease of reading.  Could be improved to indicate the
 * different control characters when printing the graph key (especially
 * the space and the newline characters)
 * 
 * Purpose:
 * To print all of the characters in the character set from 0 to 127
 * 
 * Conclusion:
 * This is not difficult to do, and there are many characters that have
 * no intelligible graphical representation.
 * */
main()
{
	int i, j, c;
	
	int charfreq[128];							//initialize charfreq[]
	for (i = 0; i < 128; ++i)					//and set each character count
		charfreq[i] = 0;						//to 0
		
	while ((c = getchar()) != EOF)				//while not EOF
		++charfreq[c];							//count each occurence of char
		
	for (i = 0; i < 128; ++i) {					//for each possible character
//		if (charfreq[i] > 0) {						//skip: if count > 0
			putchar(i);							//then print histogram row
			printf(" ");
			for (j = 0; j < charfreq[i]; ++j)
				printf("x");
			printf("\n");
//		}											//skip }
	}
}
