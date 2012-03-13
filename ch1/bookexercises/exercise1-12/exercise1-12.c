#include <stdio.h>

#define IN	1
#define OUT	0

/* exercise1-12 - Write a program that prints its input one word per
 * line
 * 
 * exercise1-12.c - uses a loop and two states to print each 'word' and
 * print a newline character at the start of contiguous 'spaces' */
main()
{
	int c, state;
	
	state = OUT;
	while ((c = getchar()) != EOF) {
		if ((c != ' ') && (c != '\t') && (c != '\n')) {	//if char is not a space
			state = IN;									//then state = in-word
			putchar(c);
		}
		else if (state == OUT)						//else if still out-of-word
			;										//do nothing
		else {										
			putchar('\n');							//else print newline
			state = OUT;							//and state = out-of-word
		}		
	}
}
