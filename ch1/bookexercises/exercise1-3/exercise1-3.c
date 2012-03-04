#include <stdio.h>

/* exercise1-3 - Modify the temperature conversion program to print a
 * heading above the table.
 * 
 * exercise1-3.c - prints a Fahrenheit to Celsius table with header */

/* print Fahrenheit-Celsius table
	for fahr = 0, 20, ..., 300 */
main()
{
	int fahr, celsius;
	int lower, upper, step;
	
	lower = 0;	/* lower limit of temperature scale */
	upper = 300;/* upper limit */
	step = 20;	/* step size */
	
	fahr = lower;
	
	printf("Fahrenheit-Celsius table:\n");	//header
	
	while (fahr <= upper) {
		celsius = 5 * (fahr-32) /9;
		printf("%3d %6d\n", fahr, celsius);
		fahr = fahr + step;
	}
}
