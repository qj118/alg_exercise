#include <stdio.h>
#include <string.h>
const int maxn = 10000;
int loc[maxn],dir[maxn],flag[maxn];
int main()
{
	int N,L,T,n;
	scanf("%d",&N);
	for(int i = 1;i <= N;i++)
	{
		scanf("%d%d%d",&L,&T,&n);
		for(int j = 0;j < n;j++)
		{
			scanf("%d%d",&loc[j],&dir[j]);// 0 == L,1 == R
		}
		while(T--)
		{
			for(int j = 0;j < n;j++)
			{
				if(dir[j] == 0) loc[j] -= 1;
				else loc[j] += 1;
			}
			memset(flag,0,sizeof(flag));
			for(int j = 0;j < n;j++)
			{
				for(int k = j+1;k < n;k++)
				{
					if(loc[j] == loc[k])
					{
						if(flag[j] == 0 && flag[k] == 0 && dir[j] != dir[k])
						{
							dir[j] = -dir[j];
							dir[k] = -dir[k];
							flag[j] = flag[k] = 1;
						}
						if(flag[j] == 0 && flag[k] == 1 && dir[j] == dir[k])
						{
							dir[j] = -dir[j];
							flag[j] == 1;
						}
						if(flag[j] == 1 && flag[k] == 0 && dir[j] == dir[k])
						{
							dir[k] = -dir[j];
							flag[k] == 1;
						}
					}
				}
			}
		}
		printf("Case #%d\n",i);
		for(int j = 0;j < n;j++)
		{
			if(loc[j] > 0 && loc[j] <= L)
			{
				printf("%d ",loc[j]);
				if(flag[j])
				   printf("Turning\n");
				else
					printf("%d\n",dir[j]);
			}
			else
				printf("Fell off\n");
		}
		printf("\n");
	}
	return 0;
}