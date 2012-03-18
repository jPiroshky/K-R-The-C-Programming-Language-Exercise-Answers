#include <stdio.h>

#define LOWERLIMIT	0
#define UPPERLIMIT	300
#define STEP		20

/* ftoc(): takes an int in fahrenheit, returns an int in celsius */
int ftoc(int fahr);

/* exercise1-15 - Rewrite the temperature conversion program of Section
 * 1.2 to use a function for conversion.
 * 
 * exercise1-15.c - prints an integer Fahrenheit to Celcius
 * temperature-conversion table using an ftoc() function to make the
 * conversion */
int main()
{
	int fahr;
	
	fahr = LOWERLIMIT;							//start at the lower limit
	
	printf("Fahrenheit to Celcius Temperature-Conversion Table:\n");
	while (fahr <= UPPERLIMIT) {				//while fahr < upper limit
		printf("%3d\t%3d\n", fahr, ftoc(fahr));	//convert and print
		fahr = fahr + STEP;
	}

	return 0;
}

/* ftoc(): takes an int in fahrenheit, returns an int in celsius */
int ftoc(int fahr) {
	return 5 * (fahr-32) /9;	//calculate and return
}
