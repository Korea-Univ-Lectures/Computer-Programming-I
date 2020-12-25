#include <stdio.h>
#include <math.h>

void result(double v);
char get_sn(double v);
int get_whl(double v);
double get_fr(double value);

int main()
{
	double value;	// input - number to analyze
	char sn;		// output - sign of value
	int whl;		// output - whole number magnitude of value
	double fr;		// output - fractional prt of value

	// gets data
	printf("Enter a value to analyze> ");
	scanf("%lf", &value);
	
	// call function
	result(value);

	return 0;
}

/*
 * Separates a number input three parts: asign(+, -, or blank),
 * a whole number magnitude, and a fractional part.
 * 
 */
void result(double v)
{
	printf("Parts of %.4f\n", v);
	printf(" \tsign: %c\n", get_sn(v));
	printf(" \twhole number magnitude: %d\n", get_whl(v));
	printf(" \tfractional part: %.4f\n", get_fr(v));
}
char get_sn(double v)
{
	if(v<0)
		return '-';
	else if(v==0)
		return ' ';
	else
		return '+';
}
int get_whl(double v)
{
	double tmp = fabs(v);
	return floor(tmp);
}
double get_fr(double v)
{
	return fabs(v)-floor(fabs(v));
}


