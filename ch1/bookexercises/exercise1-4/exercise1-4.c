#include <stdio.h>

/* exercise1-4 - Write a program to print the corresponding Celsius to
 * Fahrenheit table.
 * 
 * exercise1-4.c - prints a Celsius to Fahrenheit table */
main()
{
	float fahr, celsius, upper, lower, step;
	
	lower = -20;
	upper = 160;
	step = 10;
	celsius = lower;
	
	printf("Celsius-Fahrenheit table:\n");
	
	while(celsius <= upper) {
		fahr = (celsius * 9.0 / 5.0) + 32.0;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
