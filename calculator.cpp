#include <cstdio>
using namespace std;
int n,k,buf[100];

int next(int n,int k)
{
	if(!k)  return 0;
	long long k2 = (long long)k * k;
	int  L = 0;
	while(k2 > 0)
	{
		buf[L++] = k2 % 10;
		k2 /= 10;
	}
	if(n > L) n = L;
	int ans = 0;
	for(int i = 0;i < n;i++)
	{
		ans = ans*10 + buf[--L];
	}
	return ans;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		int ans = k;
		int k1 = k;
		while(1)
		{
			k1 = next(n,k1);
			if(ans == k1)
				break;
			if(k1 > ans)
				ans = k1;
		}
		printf("%d\n",ans);
	}
	return 0;
}