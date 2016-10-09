#include <cstdio>
#include <cstring>

typedef long long LL;
const int maxn = 510;

struct RMatrix{
	LL e[maxn];
}A,v,I;
int n,m,d,k;

RMatrix mul(RMatrix a,RMatrix b)
{
	int i,j;
	RMatrix c;
	for(i = 0;i < n;++i)
	{
		c.e[i] = 0;
		for(j = 0;j < n;++j)
		{
			c.e[i] = (c.e[i] + a.e[j] * b.e[i >= j ? (i - j):(n + i - j)]) % m;
		}
	}
	return c;
}

int main()
{
	while(scanf("%d%d%d%d",&n,&m,&d,&k) == 4 && n)
	{
		memset(v.e,0,sizeof(v.e));
		memset(A.e,0,sizeof(A.e));
		memset(I.e,0,sizeof(I.e));
		I.e[0] = 1;
		for(int i = 0;i < n;i++)
		{
			scanf("%lld",&v.e[i]);
		}
		for(int i = 0;i < n;i++)
		{
			if(i <= d || n - i <= d)
			{
				A.e[i] = 1;
			}
		}
		while(k)
		{
			if(k & 1)
				I = mul(A,I);
			A = mul(A,A);
			k >>= 1;
		}
		I = mul(I,v);
		for(int i = 0;i < n;i++)
		{
			printf("%d ",I.e[i]);
		}
		printf("\n\n");
	}
	return 0;
}