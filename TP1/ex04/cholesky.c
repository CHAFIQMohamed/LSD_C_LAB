#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10


float *descente(float A[N][N], float B[N], int n)
{
  float *x;
  x = malloc(sizeof(float) * n);
  /***************************************/
  x[0]=B[0]/A[0][0];
  for(int i=1;i<n;i++)
  {
      float s=0;
      for(int j=0;j<=i-1;j++)
      {
          s=A[i][j]*x[j];
      }
      x[i]=(B[i]-s)/A[i][i];
  }
  /***************************************/
  return x;
}

float *remontee(float A[N][N], float B[N], int n)
{
  float   *x;

  x = malloc(sizeof(float) * n);


 x[n-1]=B[n-1]/A[n-1][n-1];
 for(int i=n-2;i>=0;i--)
  {
      float s=0;
      for(int j=i+1;j<n;j++)
      {
          s=s+A[i][j]*x[j];
      }
      x[i]=(B[i]-s)/A[i][i];
  }
  /****************************************/

  return (x);
}



float *cholseky(float A[N][N], float B[N], int n)
{
	float *x;
	x= malloc(sizeof(float) *n);
	float c[n][n];
	// on calcule les coefficients de 1ere colonne
	c[0][0]=sqrt(A[0][0]);
	for(int i=1;i<n;i++)
		c[i][0]=A[i][0]/c[0][0];

	for(int j=1;j<n;j++)
	{
		for(int i=1;i<=j-1;i++)
			c[i][j]=0;
		float s=0;
		for(int k=0;k<=j-1;k++)
			s=s+c[j][k]*c[j][k];
		c[j][j]=sqrt(A[j][j]-s);
		for(int i=j+1;i<n;i++)
		{
			float d=0;
			for(int k=0;k<=j-1;k++)
				d+=c[i][k]*c[j][k];
			c[i][j]=(A[i][j]-d)/c[j][j];
		}
	}
	float ct[n][n];
	for(int i=0 ; i<n;i++)
		for(int j=0 ; j<n ;j++)
			ct[i][j]=c[j][i];
	// show the c matrix 
	for(int i=0 ; i<n;i++)
	{
                for(int j=0 ; j<n ;j++)
			printf("\n%f ",c[i][j]);
		printf("\n");
	}
	//on va resoudre c*y=b par la methode de descente
	float *Y=descente(c , B , n);
	//
	for(int i=0;i<n;i++)
		printf("%f\t",Y[i]);
	//on va resoudre ct*x=y par la methode de remontee
	x=remontee(ct , Y, n);

	return x;
}





int main()
{
  float   A[N][N], B[N];
  float   *x;
  int     n;

  printf("Enter the size of the matrix: ");
  scanf("%d", &n);

  /* Filling the matrix A */
  printf("Filling the matrix A\n");
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      printf("A[%d][%d] = ", i, j);
      scanf("%f", &A[i][j]);
    }
  }

  /* Filling the vector B*/
  printf("Filling the matrix B\n");
  for (int i = 0; i < n; i++)
  {
    printf("B[%d] = ", i);
    scanf("%f", &B[i]);
  }

  /* The calculation of the result */
  x = cholseky(A, B, n);

  /* Printing the results */
  printf("\nThe resulting vector: [");
  for (int i = 0; i < n; i++)
    printf("%f%c", x[i], ",]"[i == n - 1]);
  return (0);
}
