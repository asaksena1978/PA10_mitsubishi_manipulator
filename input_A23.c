#include<math.h>

//T matrix between link 2 and link 3, O3 is joint angle 3 
void input_A23(float *arr, float O3)
{
	*(arr) = ((-1) * sin(O3));
	*(arr + 1) = 0;
	*(arr + 2) = cos(O3);
	if((*(arr + 2)) > 0)
	{
		if((*(arr + 2)) < 0.00001)
		{
			*(arr + 2) = 0;
		}
	}
	else
	{
		if((-1 * (*(arr + 2))) < 0.00001)
		{
			*(arr + 2) = 0;
		}
	}
	*(arr + 3) = 0;

	*(arr + 4) = cos(O3);
	if((*(arr + 4)) > 0)
	{
		if((*(arr + 4)) < 0.00001)
		{
			*(arr + 4) = 0;
		}
	}
	else
	{
		if((-1 * (*(arr + 4))) < 0.00001)
		{
			*(arr + 4) = 0;
		}
	}
	*(arr + 5) = 0;
	*(arr + 6) = sin(O3);
	*(arr + 7) = 0;

	*(arr + 8) = 0;
	*(arr + 9) = 1;
	*(arr + 10) = 0;
	*(arr + 11) = 0;

	*(arr + 12) = 0;
	*(arr + 13) = 0;
	*(arr + 14) = 0;
	*(arr + 15) = 1;
}
