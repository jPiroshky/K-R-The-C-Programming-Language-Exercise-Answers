#include <stdio.h>

/* exercise1-5.c - prints a celsius to fahrenheit table in desc order */
main()
{
	float celsius, upper, lower, step;
	
	lower = -19;
	upper = 160;
	step = 20;
	celsius = lower;
	
	printf ("celsius to fahrenheit table\n");
	
	for (celsius = lower; celsius <= upper; celsius = celsius + step) 
		printf("%3.0f %6.1f\n", celsius, (celsius*9.0/5.0)+32.0);
}
