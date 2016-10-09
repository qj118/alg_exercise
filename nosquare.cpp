#include <stdio.h>
#include <math.h>
#include <string.h>
const int MAXN = 100000;
int prime[MAXN],vis[MAXN];
int c = 0;

void is_prime(int m)
{	
	int x = sqrt(m + 0.5);
	memset(vis,0,sizeof(vis));
	for(int i = 2;i <= x;i++)
	{
		if(!vis[i])
		{
			prime[c++] = i;
			for(int j = i*i; j <= m;j += i)
			{
				vis[j] = 1;
			}
		}
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int count = m - n + 1;
	is_prime(m);
	for(int i = 0;i < c;i++)
	{
		for(int j = prime[i]*prime[i];j <=m;j += prime[i]*prime[i])
		{
			if(j >= n)
			{
				count--;
			}
		}
	}
	printf("%d",count);
	return 0;
}