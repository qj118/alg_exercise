#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n,kase = 0,ans;
	while(scanf("%d",&n) == 1 && n != -1)
	{
		ans = 0;
		for(int i = 1;(1<<i) <= n;i++)
		{
			ans++;
		}
		if(n%(1<<ans)) ans++;
		printf("case: %d: %d\n",++kase,ans);
	}
	return 0;
}