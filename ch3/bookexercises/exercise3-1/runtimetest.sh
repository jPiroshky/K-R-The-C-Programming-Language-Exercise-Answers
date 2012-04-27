#!/bin/bash
# runtimetest.sh - this script runs and displays the results for the
# test of run time requested in exercise3-1.  It uses the 'time' (bash
# included) and 'gcc' programs.  If the c source code is not compiled,
# this script will compile them before running the tests.

#compile exercise3-1_vtextbook.c if not compiled already
if [ ! -f exercise3-1_vtextbook ]
then
gcc -Wall -o exercise3-1_vtextbook exercise3-1_vtextbook.c
fi

#compile exercise3-1.c if not compiled already
if [ ! -f exercise3-1 ]
then
gcc -Wall -o exercise3-1 exercise3-1.c
fi

#prompt user for the number of trials to conduct for each program
echo 'enter the number of time trials to run for each program'
read NUM_TRIALS

#begin testing exercise3-1
echo -e "\n\nbegin testing exercise3-1 ...\n"
INDEX=$NUM_TRIALS
EX31_TOTAL=0
while [ $INDEX -gt 0 ]
do
INDEX=$[$INDEX - 1]
time ./exercise3-1
done

#begin testing exercise3-1_vtextbook
echo -e "\n\nbegin testing exercise3-1_vtextbook ...\n"
INDEX=$NUM_TRIALS
EX31_TEXTBOOK_TOTAL=0
while [ $INDEX -gt 0 ]
do
INDEX=$[$INDEX - 1]
time ./exercise3-1_vtextbook
done
