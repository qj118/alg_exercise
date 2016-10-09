#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	unsigned long long n,m;
	while(scanf("%lld%lld",&n,&m) == 2)
	{
		if(!n && !m) break;
		if(n > m) swap(n,m);
		printf("%lld\n",n*m*(m+n-2)+2*n*(n-1)*(3*m-n-1)/3);
	}
	return 0;
}