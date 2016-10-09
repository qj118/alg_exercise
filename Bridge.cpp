#include <cstdio>
#include <cmath>
using namespace std;

double F(double a,double x)
{
	double a2 = a * a,x2 = x * x;
	return (x * sqrt(a2 + x2) + a2 * log(fabs(x + sqrt(a2 + x2))))/2; 
}

double parabola_arc_length(double w,double h)
{
	double a = 4.0 * h / (w*w);
	double b = 1.0 / (2*a);
	return (F(b,w/2) - F(b,0)) * 4 * a;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int kase = 1;kase <= T;kase ++)
	{
		int D,H,B,L;
		scanf("%d%d%d%d",&D,&H,&B,&L);
		int n = (B + D - 1)/D;
		double D1 = (double) B/n;
		double L1 = (double) L/n;
		double x = 0,y = H;
		while(y - x > 1e-5)
		{
			double m = x + (y - x)/2;
			if(parabola_arc_length(D1,m) < L1) x = m;
			else
			    y = m; 
		}
		if(kase > 1) printf("\n");
		printf("Case %d:\n%.2lf",kase,H - x);
	}
	return 0;
}

double simpson(double a,double b)
{
	double c = a + (b - a)/2;
	return (F(a) + 4*F(c) + F(b)) * (b-a)/6;
}

double asr(double a,double b,double eps,double A)
{
	double c = a + (b-a)/2;
	double L = simpson(a,c),R = simpson(c,b);
	if(fabs(L+R-A) <= 15*eps)
		return L + R + (L + R - A)/15.0;
	return asr(a,c,eps/2,L) + asr(c,b,eps/2,R);
}

double asr(double a,double b,double eps)
{
	return asr(a,b,eps,simpson(a,b));
}