#include<math.h>
//T matrix between link 3 and link 4, O4 is joint angle 4 L2 is link length
void input_A34(float *arr, float O4, float L2)
{
	*(arr) = cos(O4);
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
	*(arr + 2) = ((-1) * (sin(O4)));
	*(arr + 3) = 0;

	*(arr + 4) = sin(O4);
	*(arr + 5) = 0;
	*(arr + 6) = cos(O4);
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
	*(arr + 11) = L2;

	*(arr + 12) = 0;
	*(arr + 13) = 0;
	*(arr + 14) = 0;
	*(arr + 15) = 1;
}
