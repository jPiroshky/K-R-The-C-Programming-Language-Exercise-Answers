#include <stdio.h>

#define MAXLINE 1000
#define TABSTOPS 8
#define MAXCOL 80

int getnline(char line[], int maxline);
void foldline(char in[], char out[], int maxcol, int maxline, int tabstops);

/* exercise1-22 - Write a program to "fold" long input lines into two or
 * more shorter lines after the last non-blank character that occurs
 * before the n-th column of input.  Make sure your program does
 * something intelligent with very long lines, and if there are no
 * blanks or tabs before the specified column.
 * 
 * exercise1-22.c - a program that folds long input lines to fit into
 * the width given by the maximum column.  If there are no blanks on a
 * segment in a line that is being folded, then the following line is
 * tabbed to reflect the contintinuation.  If the resulting folded line
 * is too long for the memory allocated, then the line is truncated and
 * *max* appears at the end of the output line. */
void main()
{
   char linein[MAXLINE];
   char lineout[MAXLINE];

   while (getnline(linein, MAXLINE) > 0)
   {
      foldline(linein, lineout, MAXCOL, MAXLINE, TABSTOPS);
      printf("%s", lineout);
   }
}

int getnline(char line[], int maxline)
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

/* foldline() - a function that folds long input lines to fit into
 * the width given by the maximum column.  If there are no blanks on a
 * segment in a line that is being folded, then the following line is
 * tabbed to reflect the contintinuation.  If the resulting folded line
 * is too long for the memory allocated, then the line is truncated and
 * *max* appears at the end of the output line. */
void foldline(char in[], char out[], int maxcol, int maxline, int tabstops)
{
   int incurs, outcurs, linecurs;
   int lastblank;
   int isblank;
   int infstword;

   incurs = outcurs = linecurs = 0;
   lastblank = 0;
   isblank = 0;
   infstword = 1;
   while (in[incurs] != '\0')
   {
      /* if resulting string is too long, note and end line */
      if (outcurs >= maxline-8)
      {
         out[maxline-8] = '\n';
         out[maxline-7] = '*';
         out[maxline-6] = 'm';
         out[maxline-5] = 'a';
         out[maxline-4] = 'x';
         out[maxline-3] = '*';
         out[maxline-2] = '\n';
         outcurs = maxline - 1;
         break;
      }

      /* if maximum row width is exceeded */
      if (linecurs >= maxcol)
      {
         if (isblank) /* and there was a blank in the string segment, fold line */
         {
            incurs = incurs - (outcurs-lastblank);
            outcurs = lastblank;
            out[outcurs] = '\n';
            ++outcurs;
            linecurs = isblank = infstword = 0;
         }
         else         /* if no blank in previous segment, indent next segment with a tab */
         {
            out[outcurs] = '\n';
            ++outcurs;
            out[outcurs] = '\t';
            ++outcurs;
            linecurs = tabstops;
            infstword = 0;
         }
      }

      /* if current character is a space */
      if (in[incurs] == ' ')
      {
         if (infstword)   /* and at least in first word of new segment, record location */
         {
            out[outcurs] = in[incurs];
            isblank = 1;
            lastblank = outcurs;
            ++outcurs;
            ++incurs;
            ++linecurs;
         }
         else
         {
            ++incurs;
         }
      }
      else if (in[incurs] == '\t')  /* else if tab, tab out to tab stops with spaces */
      {
         if (infstword)
         {
            out[outcurs] = in[incurs];
            isblank = 1;
            lastblank = outcurs;
            ++outcurs;
            ++incurs;
            ++linecurs;
            while ((linecurs%tabstops) != 0)
            {
               ++linecurs;
            }
         }
         else
         {
            ++incurs;
         }
      }
      else                         /* copy character to output */
      {
         out[outcurs] = in[incurs];
         ++outcurs;
         ++incurs;
         ++linecurs;
         infstword = 1;
      }
   }
   out[outcurs] = '\0';
}
