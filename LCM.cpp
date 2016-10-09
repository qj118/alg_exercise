#include <cstdio>
#include <cmath>

int gcd(int a,int b)
{
	return b == 0 ? a : gcd(b,a % b);
}

int main()
{
	int T;
	int a,c,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&c);
		if(c % a != 0)
		{
			printf("No solution!\n");
		}else
		{
			b = c/a;
			for(int i = b;i <= c;i += b)
			{
				if(i/gcd(a,i) == b)
				{
					printf("%d\n",i);
					break;
				}
			}
		}
	}
	return 0;
}