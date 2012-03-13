#include <stdio.h>

#define MAXWORDLENGTH 25
#define MAXFREQ 20

/* exercise1-13 - Write a program to print a histogram of the lengths of
 * words in its input.  It is easy to draw the histogram with the bars
 * horizontal; a vertical orientation is more challenging.
 * 
 * exercise1-13 - a word-count histogram with a vertical orientation.
 * Could be improved with an automatic maximum-word-length detection,
 * intelligent table sizing upon print, and excluding punctuation from
 * count. */
main()
{
	int c, wordl, i, j;
	wordl = 0;
	
	int wordcount[MAXWORDLENGTH];				//initialize wordcount[]
	for (i = 0; i < MAXWORDLENGTH; ++i)			//and set all counts to 0
		wordcount[i] = 0;
		
	while ((c = getchar()) != EOF) {			//while next char is not EOF
		if (c != ' ' && c != '\n' && c != '\t')	//if not 'space'
			++wordl;							//then increase word-length
		else if (wordl != 0) {					//else if word-length not 0
			++wordcount[wordl - 1];				//then tally in wordcount[]
			wordl = 0;							//and reset word-length to 0
		}
	}
	
	printf("Freqency vs. Word-Length:\n");		//print histogram
	for (i = MAXFREQ; i >= 1; --i) {			//with high freqency at top
		printf("%3d", i);						//print row key
		for (j = 0; j < MAXWORDLENGTH; ++j) {	//and for each row
			if (wordcount[j] >= i)				//if wordcount[col] >= row
				printf("  x");					//print 'x'
			else
				printf("   ");					//else ' '
		}
		printf("\n");							//next row
	}
	for (i = 0; i <= MAXWORDLENGTH; ++i)		//print column key
		printf("%3d", i);
	printf("\n");
}
		
	
