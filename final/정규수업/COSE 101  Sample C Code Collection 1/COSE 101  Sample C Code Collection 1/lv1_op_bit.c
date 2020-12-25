#include <stdio.h>

int main()
{
	/*
	* Hex E6 looks like this in binary
	*  
	* 1110 0110
	*  
	* UNSIGNED is used to stop C using    
	* first 1 as an indicator of the sign
	*/
	unsigned char value='\xE6';
	
	/* Hex 7F looks like this in binary
	*
	* 0111 1111
	*/
	
	printf("%2X %2X \n", value, (value & '\x7F'));
	
	/* A bitwise AND has the effect of 
	* filtering unwanted bits. 
	*
	* 1110 0110 (E6) AND
	* 0111 1111 (7F)
	* --------- 
	* 0110 0110 (66)
	*/
	
	
	/* Hex 66 (f) looks like this in binary
	*  
	* 0110 0110
	*/
	unsigned char value='\x66';
	
	/* Hex 80 looks like this in binary
	*
	* 1000 0000
	*/
	
	printf("%2X %2X \n", value, (value | (unsigned char)'\x80'));
	
	/* A bitwise OR has the effect of 
	* adding wanted bits.      
	*
	* 0110 0110 (66) OR
	* 1000 0000 (80)
	* --------- 
	* 1110 0110 (E6)
	*/

	/****************************************************************************
	*
	* Program results are:
	*
	* 66 E6
	*
	****************************************************************************/


	//Exclusive OR
	int  One = 20;
	int  Two = 12;
	
	printf("One = %d Two = %d\n", One, Two);
	
	One ^= Two;
	Two ^= One;
	One ^= Two;
	
	printf("One = %d Two = %d\n", One, Two);

	//Bit shifting
﻿    unsigned int bytes=256; /* 00000000 00000000 00000000 10000000 */
    printf("%3d \n", bytes);

    bytes >>= 1;  /* 00000000 00000000 00000000 01000000 */
    printf("%3d \n", bytes);

    bytes >>= 1;  /* 00000000 00000000 00000000 00100000 */
    printf("%3d \n", bytes);

    bytes >>= 1;  /* 00000000 00000000 00000000 00010000 */
    printf("%3d \n", bytes);

    bytes >>= 1;  /* 00000000 00000000 00000000 00001000 */
    printf("%3d \n", bytes);

    bytes >>= 1;  /* 00000000 00000000 00000000 00000100 */
    printf("%3d \n", bytes);    

    bytes >>= 1;  /* 00000000 00000000 00000000 00000010 */
    printf("%3d \n", bytes);
    
    bytes >>= 1;  /* 00000000 00000000 00000000 00000001 */
    printf("%3d \n", bytes);

    bytes >>= 1;  /* 00000000 00000000 00000000 00000000 */
    printf("%3d \n", bytes);

	return 0;
}