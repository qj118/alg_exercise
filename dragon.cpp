#include <stdio.h>
#include <string.h>
const int maxn = 20000;
const int INF = 1000;
int dragon[maxn],knight[maxn];

int main()
{
	int n,m,cost = 0;
	while(scanf("%d%d",&n,&m) == 2)
	{
		if(n == 0 && m == 0) break;
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&dragon[i]);
		}
		for(int i = 0;i < m;i++)
		{
			scanf("%d",&knight[i]);
		}
		if(n > m) 
		{
		    printf("Loowater is doomed!\n");
		    continue;
		}
		for(int i = 0;i < n;i++)
		{
			int min = INF,minj = m+1;
			for(int j = 0;j < m;j++)
			{
				if(dragon[i] <= knight[j])
				{
					if(min > knight[j])
					{
						min = knight[j];
						minj = j;
					}
				}
			}
			if(min == INF)
			{
				printf("Loowater is doomed!\n");
				cost = 0;
				break;
			}
			cost += min;
			knight[minj] = 0;
		}
		if(cost != 0)
		{
			printf("%d\n",cost);
		}
	}
	return 0;
}