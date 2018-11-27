# include<stdio.h>
# include<math.h>

extern void display(float *);
extern void mul(float *, float *, float *);

float Px, Py, Pz;
float P4x, P4y, P4z;
float bx, by, bz;
float den, num, t0, t1, t2, t3, t4, t5;
float T03[4][4];
//inv_00 ~ inv_05 joint angles for arm(0)
//*arr pointer to T matrix
//*arr04 T matrix for wrist joint
//*arr03_inv pose for wrist joint
//L0, L1, L2, D link lengths
void inverse_kin( float *inv_O0,float *inv_O1,float *inv_O2,float *inv_O3,float *inv_O4,float *inv_O5,float *arr, float *arr04, float *arr03_inv, float L0, float L1, float L2, float D)
{
	Px = *(arr + (0 * 4) + 3);
	Py = *(arr + (1 * 4) + 3);
	Pz = *(arr + (2 * 4) + 3);

	bx = *(arr + (0 * 4) + 2);
	by = *(arr + (1 * 4) + 2);
	bz = *(arr + (2 * 4) + 2);


//	display(arr03_inv);


	P4x = (*(arr04 + (0 * 4) + 3));
	P4y = (*(arr04 + (1 * 4) + 3));
	P4z = (*(arr04 + (2 * 4) + 3));
	num = P4y;
	den = P4x;
	if(den == 0)
	{
		if(num == 0)
		{
			*(inv_O0) = 0;
		}
		else
		{
			*(inv_O0) = (3.1415926/2);
		}
	}
	else
	{
		*(inv_O0) = atan(num/den);
	}
	
	t0 = ((P4x * (cos(*(inv_O0))) + (P4y * (sin(*(inv_O0))))));
	t0 = t0 * t0;
	t1 = L0 - P4z;
	t1 = t1 * t1;
	t2 = (L1 * L1) + (L2 * L2);
	t3 = t1 + t0 - t2;
	t4 = (L1 * L2 * 2);
	t3 = t3/t4;
	t4 = 1 - (t3 * t3);
	t4 = sqrt(t4);
	num = t4;
	den = t3;
	if(den == 0)
	{
		if(num == 0)
		{
			*(inv_O2) = 0;
		}
		else
		{
			*(inv_O2) = (3.14159265/2);
		}
	}
	else
	{
		*(inv_O2) = atan(num/den);
	}


	t0 = ((P4x * (cos(*(inv_O0))) + (P4y * (sin(*(inv_O0))))));
	t1 = L0 - P4z;
	t2 = L1  + (L2 * (cos((*(inv_O2)))));
	t3 = L2 * sin(*(inv_O2));
	num = (t0 * t2) + (t1 * t3);
	den = (t0 * t3) - (t2 * t1);
	if(den == 0)
	{
		if(num == 0)
		{
			*(inv_O1) = 0;
		}
		else
		{
			*(inv_O1) = (3.14159265/2);
		}
	}
	else
	{
		*(inv_O1) = atan(num/den);
	}

	mul((&(T03[0][0])), arr03_inv, arr);

/*	printf("\nA03 inv = \n");
	display(arr03_inv);
	printf("\nT = \n");
	display(arr);
	printf("\nT\" = \n");
	display(&(T03[0][0]));*/

	bx = T03[0][2];
	by = T03[1][2];
	bz = T03[2][2];

	num = by;
	den = bx;
	if(den == 0)
	{
		if(num == 0)
		{
			*(inv_O3) = 0;
		}
		else
		{
			*(inv_O3) = (3.14159265/2);
		}
	}
	else
	{
		*(inv_O3) = atan(num/den);
	}


	t0 = (bx * (cos(*(inv_O3)))) + (by * (sin(*(inv_O3))));
	
	num = t0;
	den = bz;
	if(den == 0)
	{
		if(num == 0)
		{
			*(inv_O4) = 0;
		}
		else
		{
			*(inv_O4) = (3.14159265/2);
		}
	}
	else
	{
		*(inv_O4) = atan(num/den);
	}

	t0 = (-1 * T03[0][0] * (sin(*(inv_O3)))) + (T03[1][0] * (cos(*(inv_O3))));
	t1 = (-1 * T03[0][1] * (sin(*(inv_O3)))) + (T03[1][1] * (cos(*(inv_O3))));

	num = t0;
	den = t1;
	if(den == 0)
	{
		if(num == 0)
		{
			*(inv_O5) = 0;
		}
		else
		{
			*(inv_O5) = (3.14159265/2);
		}
	}
	else
	{
		*(inv_O5) = atan(num/den);
	}

/*	printf("\ninv O1 = %f", *(inv_O0));
	printf("\ninv O2 = %f", *(inv_O1));
	printf("\ninv O3 = %f", *(inv_O2));
	printf("\ninv O4 = %f", *(inv_O3));
	printf("\ninv O5 = %f", *(inv_O4));
	printf("\ninv O6 = %f", *(inv_O5));*/
}	
