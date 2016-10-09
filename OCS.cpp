#include <cstdio>
#include <algorithm>
using namespace std;
/*int A[100000],n;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&A[i]);
		}
		int ans = A[0] - A[1];
		int  MaxAi = A[0];
		for(int j = 1;j < n;j++)
		{
			ans = max(ans,MaxAi - A[j]);
			MaxAi = max(MaxAi,A[j]);
		}
		printf("%d\n",ans);
	}
	return 0;
}*/

int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int x,y,z;
		scanf("%d%d",&x,&y);
		int ans;
		for(int i = 2;i < n;i++)
		{
			scanf("%d",&z);
			if(x < y)
			{
				x = y;
			}
			if(y > z)
			{
				y = z;
			}
            ans = x - y;
		}
		printf("%d\n",ans);
	}
	return 0;
}