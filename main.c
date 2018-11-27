# include<stdio.h>
//verfy FK and IK for PA10 mitsubishi manipulator
extern void input_A01(float *, float, float);
extern void input_A12(float *, float, float);
extern void input_A23(float *, float);
extern void input_A34(float *, float, float);
extern void input_A45(float *, float);
extern void input_A56(float *, float, float);
extern void mul(float *, float *, float *);
extern void display(float *);
extern void inv_mat(float *, float *);
extern void inverse_kin(float *, float *, float *, float *, float *, float *, float *, float *, float *, float, float, float, float);

float A01[4][4], A12[4][4], A23[4][4], A34[4][4], A45[4][4], A56[4][4];	//Link to link FK matrix
float A04[4][4], A03[4][4], A03_inv[4][4];				//Temp matrix for inverse kinematics
float A0, A1, A2, A3, A4, A5;						//Input Joint angles for FK
float inv_A0, inv_A1, inv_A2, inv_A3, inv_A4, inv_A5, inv_A6;		//Joint angles from IK
float L0 = 315, L1 = 450, L2 = 500, D = 80/* D = 62*/;			//Link lengths
float A[4][4], temp[4][4];						//FK matrix

main()
{
	printf("\n\n\nInput displacement angles => \nAngle 1 = ");
	scanf("%f",&A0);
	A0 = (A0 * 3.14159265)/180;

	printf("\nAngle 2 = ");
	scanf("%f",&A1);
	A1 = (A1 * 3.14159265)/180;

	printf("\nAngle 3 = ");
	scanf("%f",&A2);
	A2 = (A2 * 3.14159265)/180;

	printf("\nAngle 4 = ");
	scanf("%f",&A3);
	A3 = (A3 * 3.14159265)/180;

	printf("\nAngle 5 = ");
	scanf("%f",&A4);
	A4 = (A4 * 3.14159265)/180;

	printf("\nAngle 6 = ");
	scanf("%f",&A5);
	A5 = (A5 * 3.14159265)/180;


	input_A01(&(A01[0][0]), A0, L0);

	input_A12(&(A12[0][0]), A1, L1);

	input_A23(&(A23[0][0]), A2);

	input_A34(&(A34[0][0]), A3, L2);

	input_A45(&(A45[0][0]), A4);

	input_A56(&(A56[0][0]), A5, D);

	mul((&temp[0][0]), (&A01[0][0]), (&A12[0][0]));
	transfer((&(A[0][0])),(&(temp[0][0])));

	mul((&temp[0][0]), (&A[0][0]), (&A23[0][0]));
	transfer((&(A[0][0])),(&(temp[0][0])));
	transfer((&(A03[0][0])), (&(temp[0][0])));
	inv_mat(&(A03_inv[0][0]), &(A03[0][0]));

	mul((&temp[0][0]), (&A[0][0]), (&A34[0][0]));
	transfer((&(A[0][0])),(&(temp[0][0])));
	transfer((&(A04[0][0])), (&(temp[0][0])));

	mul((&temp[0][0]), (&A[0][0]), (&A45[0][0]));
	transfer((&(A[0][0])),(&(temp[0][0])));

	mul((&temp[0][0]), (&A[0][0]), (&A56[0][0]));
	transfer((&(A[0][0])),(&(temp[0][0])));

	display((&A[0][0]));


//inverse kinematics

	inverse_kin(&(inv_A0), &(inv_A1), &(inv_A2), &(inv_A3), &(inv_A4), &(inv_A5), &(A[0][0]), &(A04[0][0]), &(A03_inv[0][0]), L0, L1, L2, D);

	inv_A0 = (inv_A0 * 180)/3.14159265;
	printf("\nAngle 1 = %f\n\n", inv_A0);
	inv_A1 = (inv_A1 * 180)/3.14159265;
	printf("\nAngle 2 = %f\n\n", inv_A1);
	inv_A2 = (inv_A2 * 180)/3.14159265;
	printf("\nAngle 3 = %f\n\n", inv_A2);
	inv_A3 = (inv_A3 * 180)/3.14159265;
	printf("\nAngle 4 = %f\n\n", inv_A3);
	inv_A4 = (inv_A4 * 180)/3.14159265;
	printf("\nAngle 5 = %f\n\n", inv_A4);
	inv_A5 = (inv_A5 * 180)/3.14159265;
	printf("\nAngle 6 = %f\n\n", inv_A5);

	return(0);
}
