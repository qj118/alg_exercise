#include <cstdio>
#include <cstring>

const int MAXN = 10000 + 10;

long long f[MAXN];
int n,w[22];

void solve()
{
	memset(f,0,sizeof(f));
	f[0] = 1;
	for(int i = 1;i < 22;i++)
	{
		w[i] = i * i * i;
	}
	for(int i = 1;i < 22;i++)
	{
		for(int j = w[i];j < 10000;j++)
		{
			f[j] += f[j-w[i]];
		}
	}
}

int main()
{
	solve();
	while(scanf("%d",&n) == 1 && n)
	{
		printf("%lld\n",f[n]);
	}
	return 0;
}