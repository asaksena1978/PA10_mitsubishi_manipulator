#include<math.h>
//T matrix between link 5 and link 6, O6 is joint angle 6 D is link length
void input_A56(float *arr, float O6, float D)
{
	*(arr) = cos(O6);
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
	*(arr + 1) = ((-1) * (sin(O6)));
	*(arr + 2) = 0;
	*(arr + 3) = 0;

	*(arr + 4) = sin(O6);
	*(arr + 5) = cos(O6);
	if((*(arr + 5)) > 0)
	{
		if((*(arr + 5)) < 0.00001)
		{
			*(arr + 5) = 0;
		}
	}
	else
	{
		if((-1 * (*(arr + 5))) < 0.00001)
		{
			*(arr + 5) = 0;
		}
	}
	*(arr + 6) = 0;
	*(arr + 7) = 0;

	*(arr + 8) = 0;
	*(arr + 9) = 0;
	*(arr + 10) = 1;
	*(arr + 11) = D;

	*(arr + 12) = 0;
	*(arr + 13) = 0;
	*(arr + 14) = 0;
	*(arr + 15) = 1;
}
