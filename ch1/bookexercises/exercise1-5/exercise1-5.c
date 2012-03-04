#include <stdio.h>

/* exercise1-5 - Modify the temperature conversion program to print the
 * table in reverse order, that is, from 300 degrees to 0.
 * 
 * exercise1-5.c - prints a celsius to fahrenheit table in desc order */
main()
{
	float celsius, upper, lower, step;
	
	lower = -20;
	upper = 160;
	step = 10;
	celsius = lower;
	
	printf("Celsius-Fahrenheit table:\n");
	
	for (celsius = upper; celsius >= lower; celsius = celsius - step) 
		printf("%3.0f %6.1f\n", celsius, (celsius*9.0/5.0)+32.0);
}
