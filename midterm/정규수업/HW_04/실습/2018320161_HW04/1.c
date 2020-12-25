#include <stdio.h>
#include <math.h>

double hypotenuse(double x, double y);

int main(void) {
	double a = 0, b = 0, c = 0;

	while (a <= 0 || b <= 0) {
		printf("Enter the side of the triangle: ");
		scanf("%lf %lf", &a, &b);
		if (a <= 0 || b <= 0) continue;
	}
	c = hypotenuse(a, b);
	printf("Hypotenuse: %.2f\n", c);


	return 0;
}

double hypotenuse(double x, double y) {
	x = sqrt((x*x) + (y*y));
	return x;
}