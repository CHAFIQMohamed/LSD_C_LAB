#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rec_droite(double (*func)(double),double a,double b,int n)
{
	double s=0;
	double h=(b-a)/n;
	double x=a;
	for(int i=0;i<n;i++)
	{
		s+=func(x);
		x+=h;
	}
	return (double)h*s;
}


double rec_gauche(double (*f)(double),double a, double b, int n)
{
	double s=0;
	double h=(b-a)/n;
	double x=a+h;
	for( int i=0; i<n;i++)
	{
		s+=f(x);
		x+=h;
	}
	return h*s;
}


double trapeze( double (*f)(double),double a,double b,int n)
{
	double s=0.5*(f(a)+f(b));
	double h=(b-a)/n;
	double x=a+h;
	for (int i=0 ; i<n-1 ; i++)
	{
		s+=f(x);
		x+=h;
	}
	return h*s;
}



double simpson(double (*f)(double),double a,double b,int n)
{
	double h=(b-a)/n;
	double x=a+h;
	double z=a+h/2;
	double I1=0;
	double I2=f(z);
	for( int i=0; i<n-1; i++)
	{
		z+=h;
		I1+=f(z);
		I2+=f(z);
		x+=h;
	}
	return (h/6)*(f(a)+f(b)+2*I1+4*I2);

}
double func(double x)
{
	return exp(x);
}


int NombreNecessaire(double (*f)(double),double a,double b, double err,double (*methode)(double(*)(double),double,double,int),double valeur)
{
	int n=1;
	while ((methode(func,a,b,n)-valeur) > err || (methode(func,a,b,n)-valeur) < -err)
	{
		n+=1;
	}
	return n;
}

int main()
{
	printf("%u",NombreNecessaire(func,0,1,0.0001,trapeze,(exp(1)-1)));
}
















