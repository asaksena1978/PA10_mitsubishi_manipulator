# include<stdio.h>
//Display T matrix
void display(float *arr)
{
	unsigned char i,j;

	printf("\n\n\n\n");

	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			printf("\t%f",(*(arr + (i * 4) + j)));
		}
		printf("\n");
	}
}
