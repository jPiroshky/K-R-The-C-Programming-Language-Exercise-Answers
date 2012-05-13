#include <ctype.h>

/* natof() - convert string s to double.  This natof is modified to
 * extend atof to handle scientific notation of the form 123.45e-6,
 * where a floating-point number may be followed by e or E and an
 * optionally signed exponent, as per exercise4-2. */
double natof(char s[])
{
	double val, power, expval, exppower;
	int i, sign, expsign;
	
	for (i = 0; isspace(s[i]); i++)  /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	if (s[i] == 'e' || s[i] == 'E')
		i++;
	expsign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (expval = 0.0; isdigit(s[i]); i++)
		expval = 10.0 * expval + (s[i] - '0');
	exppower = 1.0;
	for (; expval > 0.0; expval -= 1.0)
		exppower *= 10;
	if (expsign == -1)
		exppower = 1.0 / exppower;
		
	return sign * val / power * exppower;
}
