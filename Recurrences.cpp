#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 16;
typedef long long LL;
struct Matrix{
	LL e[maxn][maxn];
}A,I;

int d,m;
LL f[maxn],ans,n;

Matrix mul(Matrix p,Matrix q)
{
	Matrix c;
	for(int i = 1;i <= d;i++)
	{
		for(int j = 1;j <= d;j++)
		{
			c.e[i][j] = 0;
			for(int k = 1;k <= d;k++)
			{
				c.e[i][j] = (c.e[i][j] + p.e[i][k] * q.e[k][j]) % m;
			}
		}
	}
	return c;
}

void matrix_pow(int x)
{
	while(x)
	{
		if(x&1)
			I = mul(I,A);
		A = mul(A,A);
		x >>= 1;
	}
}

int main()
{
	while(scanf("%d%d%d",&d,&n,&m) == 3 && d && m && n)
	{
		memset(I.e,0,sizeof(I.e));
		memset(A.e,0,sizeof(A.e));
		for(int i = 1;i <= d;i++)
		{
			scanf("%lld",&A.e[1][i]);
		}
		I.e[1][1] = 1;
		for(int i = 2;i <= d;i++)
		{
			I.e[i][i] = 1;
			A.e[i][i-1] = 1;
		}
		for(int i = d;i >= 1;i--)
		{
			scanf("%lld",&f[i]);
		}
		if(n > d)
		{
			matrix_pow(n-d);
			ans = 0;
			for(int i = 1;i <= d;i++)
			{
				ans = (ans + f[i] * I.e[1][i]) % m;
			}
		}
		else
			ans = f[d - n + 1] % m;
		printf("%lld\n\n",ans);
	}
	return 0;
}