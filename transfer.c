//copy matrix t to arr
void transfer(float *arr, float *t)
{
	unsigned char i,j;

	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			*(arr + (i * 4) + j)  = *(t + (i * 4) + j);
		}
	}
}
