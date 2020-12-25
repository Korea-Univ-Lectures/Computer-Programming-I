#include <stdio.h>

int main()
{
	
	printf ("Characters: %c %c \n", 'a', 65);
	
	// %[][][][l]d, long decimal
	printf ("Decimals: %d %ld\n", 1977, 650000L);
	
	// %[][10][][]d, Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with BLANK spaces.
	printf ("Preceding with blanks: %10d \n", 1977);
	
	// %[0][10][][]d
	// If the value to be printed is shorter than this number, the result is padded with ZERO (0) numver.
	printf ("Preceding with zeros: %010d \n", 1977);
	
	// %[][][][]x, Unsigned hexadecimal integer
	// %[][][][]o, Unsigned octal
	// %[#][][][]x, The hexadecimal value is preceeded with 0x.
	// %[#][][][]o, The octal is preceeded with 0.
	printf ("Some different radixes: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	
	// %[][4][.2][]f, Minimum 4 characters with minimum 2 characters after decimal point.
	// %[+][][.0][]e, Display sign character, Zero digits to be printed after the decimal point, Scientific notation using 'e' character
	// %[][][][]E, Scientific notation using 'E' character.
	printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	
	// %[][*][][]d
	// * mark is filled with additional integer value argument preceding the argument that has to be formatted. 
	// The filled value is used as a width.
	printf ("Width trick: %*d \n", 5, 10);
	
	// %[][][][]s
	// String
	printf ("%s \n", "A string");
	
	return 0;
}