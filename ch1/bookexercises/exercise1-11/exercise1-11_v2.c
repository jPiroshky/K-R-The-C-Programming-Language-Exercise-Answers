#include <stdio.h>

#define IN	1	/* inside a word */
#define OUT	0	/* outside a word */

/* exercise1-11 - How would you test the word count program?  What kinds
 * of input are most likely to uncover bugs if there are any?
 * 
 * exercise1-11_v2.c - the wc program modified to copy its input to its
 * output, and to exhibit some intelligent behavior when given a
 * backspace character in input.  The solution below may still have some
 * bugs, as wctest5.in produces a negative character count as output,
 * which may or may not be unexpected or undesired behavior depending on
 * what you are using wc for. */
main()
{
	int c, nl, nw, nc, state;
	
	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '\b')	//if c is a backspace, subtract one character 
			--nc;		//from the total, and skip the counting block 
		else
		{	
			++nc;
			if (c == '\n')
				++nl;
			if (c == ' ' || c == '\n' || c == '\t')
				state = OUT;
			else if (state == OUT) {
				state = IN;
				++nw;
			}
		}
		putchar(c);	//print each character, including backspace
	}
	printf("%d %d %d\n", nl, nw, nc);
}
