#include <stdio.h>
#include <string.h>
const int MAXN = 10000;
int isp[MAXN],A[MAXN],vis[MAXN];
int n;

int  is_prime(int n)
{
	for(int i = 2;i*i <= n;i++)
	{
		if(n % i == 0)
			return 0;
	}
	return 1;
}

void dfs(int cur)
{
	if(cur == n && isp[A[0]+A[n-1]])
	{
		for(int i = 0;i < n;i++)
			printf("%d ",A[i]);
		printf("\n");
	}
	else
	{
		for(int i = 2;i <= n;i++)
		{
			if(!vis[i-1] && isp[i+A[cur-1]])
			{
				A[cur] = i;
				vis[i-1] = 1;
				dfs(cur + 1);
				vis[i-1] = 0;
			}
		}
	}
}

int main()
{
	memset(vis,0,sizeof(vis));
	memset(isp,0,sizeof(isp));
	scanf("%d",&n);
	A[0] = 1; 
	vis[0] = 1;
	isp[1] = 0;
	for(int i = 2;i <= n*2;i++)
	{
		isp[i] = is_prime(i);
	}
	dfs(1);
	return 0;
}