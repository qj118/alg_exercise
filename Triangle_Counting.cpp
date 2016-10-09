#include <cstdio>
using namespace std;

long long f[1000010];

int main()
{
	f[3] = 0;
	for(long long x = 4;x <= 1000000;x++)
	{
		f[x] = f[x-1] + ((x-1)*(x-2)/2 - (x-1)/2)/2;
	}
	int n;
	while(scanf("%d",&n) == 1 && n >= 3)
	{
		printf("%lld\n",f[n]);
	}
	return 0;
}