#include<stdio.h>
#include<math.h>
//T matrix between link 1 and link 2, O1 is joint angle 2 L1 is link length
void input_A12(float *arr, float O2, float L1)
{
	*(arr) = sin(O2);
	*(arr + 1) = cos(O2);
	if((*(arr + 1)) > 0)
	{
		if((*(arr + 1)) < 0.00001)
		{
			*(arr + 1) = 0;
		}
	}
	else
	{
		if(( -1 * (*(arr + 1))) < 0.00001)
		{
			*(arr + 1) = 0;
		}
	} 
	*(arr + 2) = 0;
	*(arr + 3) = (L1 * (sin(O2)));

	*(arr + 4) = ((-1) * (cos(O2)));
	*(arr + 5) = sin(O2);
	*(arr + 6) = 0;
	*(arr + 7) = (cos(O2));
	if((*(arr + 7)) > 0)
	{
		if((*(arr + 7)) < 0.00001)
		{
			*(arr + 7) = 0;
		}
	}
	else
	{
		if(( -1 * (*(arr + 7))) < 0.00001)
		{
			*(arr + 7) = 0;
		}
	}
	*(arr + 7) = ((-1 * L1) * (*(arr + 7)));
//	*(arr + 7) = ((-1 * L1) * (cos(O2)));
/*	if((*(arr + 7)) < 0.0001)
	{
		*(arr + 7) = 0;
	}*/

	*(arr + 8) = 0;
	*(arr + 9) = 0;
	*(arr + 10) = 1;
	*(arr + 11) = 0;

	*(arr + 12) = 0;
	*(arr + 13) = 0;
	*(arr + 14) = 0;
	*(arr + 15) = 1;
}
