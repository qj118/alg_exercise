#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110;
int n,d,r,afternoon[maxn],night[maxn];

int main()
{
	while(scanf("%d%d%d",&n,&d,&r) == 3 && n)
	{
		int  ans = 0;
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&afternoon[i]);
		}
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&night[i]);
		}
		sort(afternoon,afternoon + n);
		sort(night,night + n);
		for(int i = 0;i < n;i++)
		{
			ans += max(0,(afternoon[i] + night[n - 1 - i] - d)) * r;
		}
		printf("%d\n",ans);
	}
	return 0;
} 