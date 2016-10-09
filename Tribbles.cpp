#include <cstdio>
#include <cmath>
using namespace std;

const int maxn = 1010;
const int maxm = 1010;

int n,k,m;
double P[maxn],f[maxm];

int main()
{
	int T,num;
	scanf("%d",&T);
	num = T;
	while(T--)
	{
		scanf("%d%d%d",&n,&k,&m);
		for(int i = 0;i < n;i++)
		{
			scanf("%lf",&P[i]);	
		}
		f[0] = 0;
	    f[1] = P[0];
	    for(int i = 2;i <= m;i++)
	    {
	    	f[i] = 0;
	    	for(int j = 0;j < n;j++)
	    	{
	    		f[i] += P[j] * pow(f[i - 1],j);
	    	}
	    }
	    printf("Case #%d: %.7lf\n",num - T,pow(f[m],k));
	}
	return 0;
}
