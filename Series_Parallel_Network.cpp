#include <cstdio>
#include <cstring>
using namespace std;

long long C(long long n,long long m)
{
	double ans = 1;
	for(int i = 0;i < m;i ++)
	{
		ans *= (n-i);
	}
	for(int i = 0;i < m;i++)
	{
		ans /= (i+1);
	}
	return (long long)(ans + 0.5);
}

const int maxn = 30 + 5;
long long f[maxn];
long long d[maxn][maxn];

int main()
{
	f[1] = 1;
	memset(d,0,sizeof(d));
	int n = 30;
	for(int i = 0;i <= n;i++)
	{
		d[i][0] = 1;
	}
	for(int i = 1;i <= n;i++)
	{
		d[i][1] = 1;
		d[0][i] = 0;
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 2;j <= n;j++)
		{
			d[i][j] = 0;
			for(int p = 0; p*i <= j;p++)
			{
				d[i][j] += C(f[i]+p-1,p) * d[i-1][j-p*i];
			}
		}
		f[i+1] = d[i][i+1];
	}
	while(scanf("%d",&n) == 1 && n)
	{
		if(n == 1)
			printf("%d\n",n);
		else
			printf("%lld\n",2*f[n]);
	}
	return 0;
}