#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 4000000;
typedef long long LL;
LL S[maxn+1],f[maxn+1];
LL phi[maxn];

void phi_table(int n)
{
	for(int i = 2;i <= n;i++)
	{
		phi[i] = 0;
	}
	phi[1] = 1;
	for(int i = 2;i <= n;i++)
	{
		if(!phi[i])
		{
			for(int j = i;j <= n;j += i)
			{
				if(!phi[j])
					phi[j] = j;
				phi[j] = phi[j]/i * (i-1);
			}
		}
	}
}

int main()
{
	phi_table(maxn);
	memset(f,0,sizeof(f));
	for(int i = 1;i <= maxn;i++)
	{
		for(int n = i*2;n <= maxn;n += i)
		{
			f[n] += i*phi[n/i];
		}
	}
	S[2] = f[2];
	for(int n = 3;n <= maxn;n++)
	{
		S[n] = S[n-1] + f[n];
	}

	int n;
	while(scanf("%d",&n) == 1 && n)
	{
		printf("%lld\n",S[n]);
	}
	return 0;
}