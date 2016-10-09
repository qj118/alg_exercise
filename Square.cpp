#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 510;
const int maxp = 100;
typedef int Matrix[maxn][maxn];

int vis[maxn];
int prime[maxp];

void sieve(int n)
{
	int m = (int)sqrt(n + 0.5);
	memset(vis,0,sizeof(vis));
	for(int i = 2;i <= m;i++)
	{
		if(!vis[i])
		{
			for(int j = i * i;j <= n;j += i)
			{
				vis[j] = 1;
			}
		}
	}
}

int gen_primes(int n)
{
	sieve(n);
	int c = 0;
	for(int i = 2;i <= n;i++)
	{
		if(!vis[i])
		{
			prime[c++] = i;
		}
	}
	return c;
}

int rank(Matrix A,int m,int n)
{
	int i = 0,j = 0,k,r,u;
	while(i < m && j < n)
	{
		r = i;
		for(k = i;k < m;k++)
		{
			if(A[k][j])
			{
				r = k;
				break;
			}
		}
		if(A[r][j])
		{
			if(r != i)
			{
				for(k = 0;k <= n;k++)
				{
					swap(A[r][k],A[i][k]);
				}
			}
			for(u = i + 1;u < m;u++)
			{
				if(A[u][j])
				{
					for(k = j;k <= n;k++)
					{
						A[u][k] ^= A[i][k];
					}
				}
			}
			i++;
		}
		j++;
	}
	return i;
}

Matrix A;

int main()
{
	int m = gen_primes(500);

	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,maxm = 0;
		long long x;
		scanf("%d",&n);
		memset(A,0,sizeof(A));
		for(int i = 0;i < n;i++)
		{
			scanf("%lld",&x);
			for(int j = 0;j < m;j++)
			{
				while(x % prime[j] == 0)
				{
					maxm = max(maxm,j);
					//printf("maxm = %d",maxm);
					x /= prime[j];
					A[j][i] ^= 1;
				}
			}
		}
//		printf("maxm = %d\n",maxm);
		int r = rank(A,maxm + 1,n);
//		printf("r = %d\n",r);
//		printf("n - r = %d\n",n - r);
//		long long ans = pow(2,n-r) - 1;
        long long ans = (1<<(n-r)) - 1;
		printf("%lld\n",ans);
	}
	return 0;
}