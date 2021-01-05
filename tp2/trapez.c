#include <stdio.h>
#include <stdlib.h>

float func( float x)
{
	return x;
}

float trapeze( float (*f)(float),float a,float b,int n)
{
	float s=0.5*(f(a)+f(b));
	float h=(b-a)/n;
	float x=a+h;
	for (int i=0 ; i<n-1 ; i++)
	{
		s+=f(x);
		x+=h;
	}
	return h*s;
}

int main()
{
	float s=trapeze(func,0,1,200);
	printf("%lf",s);
	return 0;
}

