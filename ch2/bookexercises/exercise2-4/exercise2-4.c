#include <stdio.h>

#define MAXLINE 1000 /* maximum per line length from std. input */

void squeeze(char s1[], char s2[]);
int ngetline(char s[], int lim);

/* exercise2-4 - Write an alternative version of squeeze(s1,s2) that
 * deletes each character in s1 that matches any character in the string
 * s2.
 * 
 * exercise2-4.c - a program that implements the function
 * squeeze(s1, s2), which takes two strings and removes from the first
 * all characters that appear in the second. */
int main()
{
	char s1[MAXLINE], s2[MAXLINE];
	
	//prompt user for a string to be transformed
	printf("enter a line (max 1000 chars) to be transformed:\n");
	ngetline(s1, MAXLINE);
	
	//prompt user for a string to match against
	printf("enter a line (max 1000 chars) to remove from the previous\n"
	"line all occurences of characters from this line:\n");
	ngetline(s2, MAXLINE);
	
	//apply transformation
	squeeze(s1, s2);
	
	//print result
	printf("here is the first line, transformed:\n%s\n", s1);
	
	return 0;
}

/* squeeze() - deletes from s1[] any characters in s2[]. Each char in 
 * s1 is compared against chars in s2 until match, and if match, then 
 * s1[]'s read position is advanced relative to its write position.*/ 
void squeeze(char s1[], char s2[])
{
	int readcursor_s1, writecursor_s1, cursor_s2, ismatch;
	
	readcursor_s1 = writecursor_s1 = cursor_s2 = 0;
	
	//while there is another character to read in s1
	while (s1[readcursor_s1] != '\0')
	{
		ismatch = 0;
		
		//traverse through s2 while !ismatch
		for (cursor_s2 = 0; !ismatch && (s2[cursor_s2] != '\0'); ++cursor_s2)
		{
			//and if a character matches
			if (s1[readcursor_s1] == s2[cursor_s2])
			{
				ismatch = 1;
			}
		}
		
		//then only advance readcursor_s1
		if (ismatch)
		{
			++readcursor_s1;
		}
		//else, copy char s1[readcursor_s1] to s1[writecursor_s1]
		//and advance both readcursor_s1 and writecursor_s1
		else
		{
			s1[writecursor_s1] = s1[readcursor_s1];
			++readcursor_s1;
			++writecursor_s1;
		}
	}
	
	//after traversing s1, add the nullchar after the last written char
	s1[writecursor_s1] = '\0';
}

/* ngetline() - read a line into s, return length */
int ngetline(char s[], int lim)
{
	int c, i;
	
	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if(c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
