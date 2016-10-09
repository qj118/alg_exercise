#include <stdio.h>
const int MAXN = 1000;
int tot,n;
int C[MAXN];

void search(int cur)
{
	int i,j;
	if(cur == n)
	{
		tot++;
		for(i = 0;i < n;i++)
		{
			printf("(%d,%d)",i,C[i]);
		}
		printf("\n");
	}
	else
	{
		for(i = 0;i < n;i++)
		{
			int ok = 1;
			C[cur] = i;
			for(j = 0;j < cur;j++)
			{
				if(C[cur] == C[j] || cur - C[cur] == j - C[j] || cur + C[cur] == j + C[j])
				{
					ok = 0;
					break;
				}
			}
			if(ok)
			{
				search(cur + 1);
			}
		}
	}
}
int main()
{
	tot = 0;
	scanf("%d",&n);
	search(0);
	printf("%d\n",tot);
	return 0;
}