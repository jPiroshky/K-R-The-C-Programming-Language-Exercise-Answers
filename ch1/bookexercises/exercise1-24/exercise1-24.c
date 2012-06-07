#include <stdio.h>

#define MAXLINE 1000

int getnline(char line[], int maxline);

/* exercise1-24 - Write a program to check a C program for rudimentary
 * syntax errors like unmatched parentheses, brackets and braces.  Don't
 * forget about quotes, both single and double, escape sequences, and
 * comments. (This program is hard if you do it in full generality.)
 * 
 * exercise1-24.c - performs a rudimentary syntax check that notifies
 * the user of how many unopened/unclosed parentheses, brackets, braces,
 * single quotes, double quotes, and multi-line comments exist.  Text
 * inside comments is not tallied for syntax check.  */
void main()
{
   char linein[MAXLINE];
   char lineout[MAXLINE];
   int prevchar;
   int incurs, outcurs;
   int insquote, indquote, inscomment, inmcomment, inescape;
   int numsquote, numdquote, nummcomment, numbrack, numparenth, numbrace;

   insquote = indquote = inscomment = inmcomment = inescape = numsquote = numdquote = nummcomment = numbrack = numparenth = numbrace = 0;
   while (getnline(linein, MAXLINE) > 0)
   {
      incurs = outcurs = 0;
      prevchar = '\0';
      while (linein[incurs] != '\n')
      {
         if (linein[incurs]=='\\' && prevchar!='\\')   //handle escape sequences
         {
            inescape = 1;
            lineout[outcurs] = linein[incurs];
            ++incurs;
            ++outcurs;
         }
         else if (linein[incurs]=='\'' && !inescape)   //handle single quote
         {
            if (!insquote && !indquote && !inmcomment)
            {
               insquote = 1;
               lineout[outcurs] = linein[incurs];
               ++incurs;
               ++outcurs;
               ++numsquote;
            }
            else if (insquote)
            {
               insquote = 0;
               lineout[outcurs] = linein[incurs];
               ++incurs;
               ++outcurs;
               --numsquote;
            }
            else 
            {
               lineout[outcurs] = linein[incurs];
               ++incurs;
               ++outcurs;
            }
         }
         else if (linein[incurs]=='\"' && !inescape)   //handle double quote
         {
            if (!insquote && !indquote && !inmcomment)
            {
               indquote = 1;
               lineout[outcurs] = linein[incurs];
               ++incurs;
               ++outcurs;
               ++numdquote;
            }
            else if (indquote)
            {
               indquote = 0;
               lineout[outcurs] = linein[incurs];
               ++incurs;
               ++outcurs;
               --numdquote;
            }
            else 
            {
               lineout[outcurs] = linein[incurs];
               ++incurs;
               ++outcurs;
            }
         }
         else if (linein[incurs]=='/' && linein[incurs+1]=='/' && !insquote && !indquote && !inscomment && !inmcomment)  //start single comment
         {
            inscomment = 1;
            lineout[outcurs] = '/';
            ++incurs;
            ++outcurs;
            lineout[outcurs] = '/';
            ++incurs;
            ++outcurs;
         }
         else if (linein[incurs]=='/' && linein[incurs+1]=='*' && !insquote && !indquote && !inscomment && !inmcomment)  //start multi-line comment
         {
            inmcomment = 1;
            lineout[outcurs] = '/';
            ++incurs;
            ++outcurs;
            lineout[outcurs] = '*';
            ++incurs;
            ++outcurs;
            ++nummcomment;
         }
         else if (linein[incurs]=='*' && linein[incurs+1]=='/' && inmcomment && !insquote && !indquote && !inscomment)  //end multi-line comment
         {
            inmcomment = 0;
            lineout[outcurs] = '*';
            ++incurs;
            ++outcurs;
            lineout[outcurs] = '/';
            ++incurs;
            ++outcurs;
            --nummcomment;
         }
         else
         {
            if (!insquote && !indquote && !inscomment && !inmcomment)   //count brackets, parentheses, and braces
            {
               if (linein[incurs] == '[')
                  ++numbrack;
               else if (linein[incurs] == ']')
                  --numbrack;
               else if (linein[incurs] == '(')
                  ++numparenth;
               else if (linein[incurs] == ')')
                  --numparenth;
               else if (linein[incurs] == '{')
                  ++numbrace;
               else if (linein[incurs] == '}')
                  --numbrace;
            }
            lineout[outcurs] = linein[incurs];
            ++incurs;
            ++outcurs;
            inescape = 0;
         }
      }
      lineout[outcurs] = '\n';
      lineout[outcurs+1] = '\0';
      printf("%s", lineout);
      inscomment = 0;
   }
   
   printf("\nThere are:\n");   //print summary
   if (numbrack > 0)
      printf("\t%d unclosed brackets.\n", numbrack);
   if (numbrack < 0)
      printf("\t%d unopened brackets.\n", (-1)*numbrack);
   if (numparenth > 0)
      printf("\t%d unclosed parentheses.\n", numparenth);
   if (numbrack < 0)
      printf("\t%d unopened parentheses.\n", (-1)*numparenth);
   if (numbrace > 0)
      printf("\t%d unclosed braces.\n", numbrace);
   if (numbrace < 0)
      printf("\t%d unopened braces.\n", (-1)*numbrace);
   if (numsquote > 0)
      printf("\t%d unclosed single quotations.\n", numsquote);
   if (numsquote < 0)
      printf("\t%d unopened single quotations.\n", (-1)*numsquote);
   if (numdquote > 0)
      printf("\t%d unclosed double quotations.\n", numdquote);
   if (numdquote < 0)
      printf("\t%d unopened double quotations.\n", (-1)*numdquote);
   if (nummcomment > 0)
      printf("\t%d unclosed multi-line comments.\n", nummcomment);
   if (nummcomment < 0)
      printf("\t%d unopened multi-line comments.\n", (-1)*nummcomment);
}

           

int getnline(char line[], int maxline)   //getnline function
{
   int c, i;

   for (i=0; i < maxline-1 && (c=getchar())!=EOF && c!='\n'; ++i)
      line[i] = c;
   if (c == '\n') {
      line[i] = c;
      ++i;
   }
   line[i] = '\0';
   return i;
}
