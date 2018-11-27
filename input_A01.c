#include<math.h>
//T matrix between base and link 1, O1 is joint angle 1 L0 is link length
void input_A01(float *arr, float O1, float L0)
{
	arr(1, 1) = cos(O1);
	if((*(arr)) > 0)
	{
		if((*(arr)) < 0.00001)
		{
			*(arr) = 0;
		}
	}
	else
	{
		if((-1 * (*(arr))) < 0.00001)
		{
			*(arr) = 0;
		}
	}
	*(arr + 1) = 0;
	*(arr + 2) = ((-1) * (sin(O1)));
	*(arr + 3) = 0;

	*(arr + 4) = sin(O1);
	*(arr + 5) = 0;
	*(arr + 6) = cos(O1);
	if((*(arr + 6)) > 0)
	{
		if((*(arr + 6)) < 0.00001)
		{
			*(arr + 6) = 0;
		}
	}
	else
	{
		if((-1 * (*(arr + 6))) < 0.00001)
		{
			*(arr + 6) = 0;
		}
	}	
	*(arr + 7) = 0;

	*(arr + 8) = 0;
	*(arr + 9) = -1;
	*(arr + 10) = 0;
	*(arr + 11) = L0;

	*(arr + 12) = 0;
	*(arr + 13) = 0;
	*(arr + 14) = 0;
	*(arr + 15) = 1;
}
