#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 250 * 250;
const int INF =  10000000;
int S[maxn],g[maxn],d[maxn];
int num[maxn];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N,p,q,x;
		scanf("%d%d%d",&N,&p,&q);
		memset(num,0,sizeof(num));
		for(int i = 1;i <= p+1;i++)
		{
			scanf("%d",&x);
			num[x] = i;
		}
		int n = 0;
		for(int i = 0;i < q+1;i++)
		{
			scanf("%d",&x);
			if(num[x])
				S[n++] = num[x];
		}
		for(int i = 1;i <= n;i++)
		{
			g[i] = INF;
		}
		int ans = 0;
		for(int i = 0;i < n;i++){
			int k  = lower_bound(g+1,g+n+1,S[i]) - g;
			d[i] = k;
			g[k] = S[i];
			ans =  max(ans,d[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}