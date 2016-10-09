#include <cstdio>
#include <cmath>
#include <cstring>

const int maxn = 1000000 + 10;
const int maxp = 700000;
int vis[maxn];
int prime[maxp],prime_cnt;
double f[maxn];

void sieve(int n)
{
	int m = (int) sqrt(n + 0.5);
	memset(vis,0,sizeof(vis));
	for(int i = 2;i <= m;i++)
	{
		if(!vis[i])
		{
			for(int j = i*i;j <= n;j += i)
			{
				vis[j] = 1;
			}
		}
	}
}

int gen_prime(int n)
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

double dp(int x)
{
	if(x == 1)
		return 0.0;
	if(vis[x]) return f[x];
	vis[x] = 1;
	double& ans = f[x];
	int g = 0,p = 0;
	ans = 0;
	for(int i = 0;i < prime_cnt && prime[i] <= x;i++)
	{
		p++;
		if(x % prime[i] == 0)
		{
			g++;
			ans += dp(x/prime[i]);
		}
	}
	ans = (ans + p)/g;
	return ans;
}

int main()
{
	prime_cnt = gen_prime(maxn);
	memset(vis,0,sizeof(vis));
	int T,N;
	scanf("%d",&T);
	for(int kase = 1;kase <= T;kase++)
	{
		scanf("%d",&N);
		dp(N);
		printf("Case #%d:%f\n",kase,f[N]);
	}
	return 0;
}