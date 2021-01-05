#include <stdio.h>
#include <stdlib.h>

float func( float x)
{
	return x;
}

float rec_droite(float (*func)(float),float a,float b,int n)
{
	float s=0;
	float h=(b-a)/n;
	float x=a;
	for(int i=0;i<n;i++)
	{
		s+=func(x);
		x+=h;
	}
	return h*s;
}

int main()
{
	float s=rec_droite(func,0,2,2000000);
	printf("%lf",s);
	return 0;
}
