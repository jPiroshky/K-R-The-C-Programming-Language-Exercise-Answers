#include <stdio.h>

#define IN	1	/* inside a word */
#define OUT	0	/* outside a word */

/* exercise1-11 - How would you test the word count program?  What kinds
 * of input are most likely to uncover bugs if there are any?
 * 
 * exercise1-11.c - To test the word count program, one would look for
 * sets of input that when operated on produce undesired or unexpected
 * output.  Two kinds of input that are likely to uncover bugs are input
 * that test the 'edge conditions' of the program, and also input that
 * is unexpected.
 * 
 * 	wctest1.in through wctest4.in test a few 'edge conditions' of the
 * program by making sure that the program responds intelligently when
 * given input that tests the 'boundaries' of our test conditions, like
 * a null input, or input that causes our program to change states.
 * The test cases wctest1.in through wctest4.in all produce expected and
 * desired output, so the program does a pretty good job of handling the
 * cases it was designed to handle.
 * 
 * 	wctest5.in through wctest8.in are designed to test unexpected input,
 * and are variations of the previous test cases.  These cases test
 * unexpected input by introducing a control character, specifically a
 * backspace, that is not handled explicitly by the program and also
 * may be unlikely in word count input, and is therefore unexpected.
 * Each one of these cases demonstrates a way that a backspace character
 * can throw-off the word count totals by at least a two characters, and
 * in some cases an extra word or an extra newline from what might be
 * expected if a human carried out the word count task. 
 * 
 * Files of the name wctest*.in are test cases for the word count
 * problem and are to be passed to exercise1-11 or exercise1-11_v1.c as
 * standard input.  The contents of each file are listed below:
 * 
 * wctest1.in
 * ''
 *
 * wctest2.in
 * ' '
 *
 * wctest3.in
 * ' \n
 *  '
 * 
 * wctest4.in
 * 'mis space'
 * 
 * wctest5.in
 * '^H'
 * 
 * wctest6.in
 * ' ^H'
 * 
 * wctest7.in
 * ' \n
 * ^H '
 * 
 * wctest8.in
 * 'mis ^Hspace'	*/
 
main()
{
	int c, nl, nw, nc, state;
	
	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
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
	printf("%d %d %d\n", nl, nw, nc);
}
