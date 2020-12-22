#include <stdio.h>
#include <stdlib.h>
#define N 10

float *descente(float A[N][N], float B[N], int n)
{

  /* A hint: you cant return an array which is allocated in the stack memory. \
  ** you may consider to create a dynamically allocated array and return a pointer to it. \
  ** https://gribblelab.org/CBootCamp/7_Memory_Stack_vs_Heap.html
  */

  /******Implement the solution here******/
  /***************************************/
   float *x;
  x = malloc(sizeof(float) * n);
  /***************************************/
  x[0]=B[0]/A[0][0];
  for(int i=1;i<n;i++)
  {
      int s=0;
      for(int j=0;j<=i-1;j++)
      {
          s=A[i][j]*x[j];
      }
      x[i]=(B[i]-s)/A[i][i];
  }
  /***************************************/
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
  printf("Filling the vector B\n");
  for (int i = 0; i < n; i++)
  {
    printf("B[%d] = ", i);
    scanf("%f", &B[i]);
  }

  /* The calculation of the result */
  x = descente(A, B, n);

  /* Printing the results */
  printf("\nThe resulting vector: [");
  for (int i = 0; i < n; i++)
    printf("%f%c", x[i], ",]"[i == n - 1]);
}

