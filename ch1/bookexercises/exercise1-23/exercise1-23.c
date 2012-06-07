#include <stdio.h>

#define MAXLINE 1000

int getnline(char line[], int maxline);

/* exercise1-23 - Write a program to remove all comments from a C
 * program.  Don't forget to handle quoted strings and character
 * constants properly.  C comments don't nest. 
 * 
 * exercise1-23.c - a program that removes all comments from a c program
 * */
void main()
{
   char linein[MAXLINE];
   char lineout[MAXLINE];
   int prevchar;
   int incurs, outcurs;
   int insquote, indquote, inscomment, inmcomment, inescape;

   insquote = indquote = inscomment = inmcomment = inescape = 0;
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
            }
            else if (insquote)
            {
               insquote = 0;
               lineout[outcurs] = linein[incurs];
               ++incurs;
               ++outcurs;
            }
            else
            {
               if (!inmcomment && !inscomment)	
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
            }
            else if (indquote)
            {
               indquote = 0;
               lineout[outcurs] = linein[incurs];
               ++incurs;
               ++outcurs;
            }
            else
            {
               if (!inmcomment && !inscomment)
                  lineout[outcurs] = linein[incurs];
               ++incurs;
               ++outcurs;
            }
         }
         else if (linein[incurs]=='/' && linein[incurs+1]=='/' && !insquote && !indquote && !inscomment && !inmcomment)  //start single comment
         {
            inscomment = 1;
            incurs = incurs + 2;
         }
         else if (linein[incurs]=='/' && linein[incurs+1]=='*' && !insquote && !indquote && !inscomment && !inmcomment)  //start multi-line comment
         {
            inmcomment = 1;
            incurs = incurs + 2;
         }
         else if (linein[incurs]=='*' && linein[incurs+1]=='/' && inmcomment && !insquote && !indquote && !inscomment)  //end multi-line comment
         {
            inmcomment = 0;
            incurs = incurs + 2;
         }
         else if (inscomment || inmcomment)
         {
            ++incurs;
         }
         else
         {
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
