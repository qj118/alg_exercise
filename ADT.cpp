#include <cstdio>

long long f(int *P,int i,int final)
{
	if(i == 0) return 0;
	if(P[i] == final) return f(P,i-1,final);
	return f(P,i-1,6-P[i]-final) + (1LL << (i-1));
}

const int maxn = 60 + 10;
int n,start[maxn],final[maxn];

int main()
{
	int caseno = 0;
	while(scanf("%d",&n) == 1 && n)
	{
		for(int i = 1;i <= n;i++)
		{
			scanf("%d",&start[i]);
		}
		for(int i = 1;i <= n;i++)
		{
			scanf("%d",&final[i]);
		}
		int k = n;
		while(k >= 1 && start[k] == final[k])
		{
			k--;
		}
		long long ans = 0;
		if(k >= 1)
		{
			int other = 6 - start[k] - final [k];
			ans = f(start,k-1,other) + f(final,k-1,other) + 1;
		}
		printf("Case %d: %lld\n",++caseno,ans);
	}
	return 0;
}