#include <stdio.h>
#include <stdlib.h>

float func( float x)
{
	return x;
}

float rec_gauche(float (*f)(float),float a, float b, int n)
{
	float s=0;
	float h=(b-a)/n;
	float x=a+h;
	for( int i=0; i<n;i++)
	{
		s+=f(x);
		x+=h;
	}
	return h*s;
}

int main()
{
	float s=rec_gauche(func,0,1,200);
	printf("%lf",s);
}

