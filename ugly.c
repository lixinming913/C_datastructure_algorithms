#include<stdio.h>
#define true 1
#define false 0

int IsUgly( int number )
{
	while( number % 2 == 0 )
		number /= 2;
	while( number % 3== 0 )
		number /= 3;
	while( number % 5 == 0 )
		number /= 5;
		
	return ( number == 1)?false:true;

}

int GetUglyNumber( int index )
{
	if( index <= 0 )
		return 0;
	
	int number = 0;
	int UglyFound = 0;
	while( UglyFound < index )
	{
		++number;
		if( IsUgly( number ))
			++UglyFound;
	}
	return number;
}
void main( )
{
	int number =  GetUglyNumber(1500);
	printf(" The 1500 ugly number is : %d \n", number);
}