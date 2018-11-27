//# include<stdio.h>

//matrix mulatiplication
void mul(float *arr, float *arr1,float *arr2)
{
	unsigned char i,j,k;

	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			*(arr + (i * 4) + j) = 0;
			for(k = 0; k < 4; k++)
			{
				*(arr +(4 * i) +j) = ((*(arr + (i * 4) + j)) + ((*(arr1 + (i * 4) + k)) * (*(arr2 + j + (k * 4)))));
			}
		}
	}
}
