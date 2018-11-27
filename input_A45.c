#include<math.h>
//T matrix between link 4 and link 5, O5 is joint angle
void input_A45(float *arr, float O5)
{
	*(arr) = cos(O5);
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
	*(arr + 2) = sin(O5);
	*(arr + 3) = 0;

	*(arr + 4) = sin(O5);
	*(arr + 5) = 0;
	*(arr + 6) = ((-1) * (cos(O5)));
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
	*(arr + 9) = 1;
	*(arr + 10) = 0;
	*(arr + 11) = 0;

	*(arr + 12) = 0;
	*(arr + 13) = 0;
	*(arr + 14) = 0;
	*(arr + 15) = 1;
}
