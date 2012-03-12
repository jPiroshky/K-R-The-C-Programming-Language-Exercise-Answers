#include <stdio.h>

/* exercise1-8 - Write a program to count blanks, tabs, and newlines.
 * 
 * exercise1-8_v1.c - Reads from std. input, copies input to output and
 * counts blanks, tabs, and newlines, then prints the results.
 * 
 * Purpose: 
 * I wanted to understand why my exercise1-8.c only prints to output
 * once EOF is reached, while my exercise1-9.c prints to output after
 * every newline character is input, so I created exercise1-8_v1.c that
 * also copies its input to output.  I believe the printing of output on
 * receiving a newline is related to the terminal's behavior rather than
 * something specific to the c language.
 * 
 * Conclusion:
 * When using getchar() in a loop, the first character is only recieved
 * after it is sent from the standard input, so in the case of running
 * exercise1-8.c or exercise1-9.c with standard input from the terminal,
 * the program only 'sees' input once the first newline is entered on
 * the terminal, and is otherwise 'waiting' at the test condition at the
 * top of the loop.  So, a program like exercise1-8.c is really tallying
 * the target characters as it recieves each new line of input, and
 * since it has not recieved an EOF, it waits for the next input.  A
 * program like exercise1-9 is also 'waiting' for input, but as it
 * recieves the new line, the program goes through the loop until input
 * is EOF or it is 'waiting' for input again, and on each iteration
 * prints the current character, effectively printing the whole line,
 * \n and all, before it is 'waiting' again.  This also explains why
 * entering characters at the terminal and then giving a single ^d
 * before typing a newline character will mirror the input to the output
 * without advancing the standard output to a new line; ^d sends the
 * input to the program from the terminal, and then the output is
 * immediatly sent and displayed on the standard output, and the program
 * continues to 'wait' for input because it did not recieve an EOF
 * character - only the terminal recieved an EOF character.  Therefore,
 * entering ^d again or at the beginning of new input will end the
 * program because this causes the terminal to send an EOF character to
 * the c program and the program at last 'sees' the EOF character,
 * effectively falsifying the loop condition and then reaching the end
 * of the program.  Truly, the question I should have asked is not 'why
 * does exercise1-9 print output after recieving a newline character'
 * but instead, 'why do I not print character tallying information from
 * exercise1-8 until I am done with the loop that takes characters from
 * the standard input'. */
main()
{
	int c, blanks, tabs, nls;
	
	blanks = 0;
	tabs = 0;
	nls = 0;
	
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++blanks;
		if (c == '\t')
			++tabs;
		if (c == '\n')
			++nls;
	putchar(c);
	}
	
	printf("in the input text, there were\n%3d blanks,\n%3d tabs, and\n%3d newlines\n", blanks, tabs, nls);
}
