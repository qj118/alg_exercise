#include <cstdio>
using namespace std;

long long SG(long long x)
{
	return x%2 == 0 ? x/2 : SG(x/2);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		long long a,v = 0;
		scanf("%d",&n);
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&a);
			v ^= SG(a);
		}
		if(v) printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}