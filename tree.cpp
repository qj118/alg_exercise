#include <stdio.h>
#include <math.h>
double area2(double x0,double y0,double x1,double y1,double x2,double y2)
{
	return fabs(x0 * y1 + x2 * y0 + x1 * y2 - x2 *y1 - x0 *y2 - x1 * y0);
}
int main()
{
	double ax,ay,bx,by,cx,cy,eps = 1e-9;
	while((scanf("%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&cx,&cy)) == 6)
	{
		int count = 0;
		ax *= 100;
		ay *= 100;
		bx *= 100;
		by *= 100;
		cx *= 100;
		cy *= 100;
		for(int i = 1;i <= 99;i++)
		{
			for(int j = 1;j <= 99;j++)
			{
				double s1 = area2(ax,ay,bx,by,cx,cy);
				double s2 = area2(i*100,j*100,ax,ay,bx,by);
				double s3 = area2(i*100,j*100,bx,by,cx,cy);
				double s4 = area2(i*100,j*100,cx,cy,ax,ay);
				if((s1 - (s2 + s3 + s4)) <= eps)
				{
					count++;
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}