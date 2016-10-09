#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 5010;
int w[maxn],e[maxn];
int n;

int r(int num)
{
	return max(0,num - 1);
}

bool ok(int rank)
{
	int sumw = 0,sume = 0,diff1 = 0,diff2 = 0;
	int can_remove = 0;
	for(int i = 1;i <= n;++i)
	{
		sumw += w[i];
		sume += e[i];
		if(r(sumw) > rank)
			diff1 = r(sumw) - rank;
		else
			diff1 = 0;
		if(r(sume) > rank)
			diff2 = r(sume) - rank;
		else
			diff2 = 0;
		if(diff1 + diff2 > can_remove)
			return false;
		if(sumw == 0 && sume > 0)
			--sume;
		else if (sume == 0 && sumw > 0)
			--sumw;
		else if(sume > 0 && sumw > 0 && sume + sumw > can_remove)
			++can_remove;
	}
	return true;
}

int solve(int L,int R)
{
	while(L < R)
	{
		int M = (L + R)/2;
		if(ok(M)) R = M;
		else
		    L = M + 1;
	}
	return L;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i = 1;i <= n;i++)
		{
			scanf("%d%d",&w[i],&e[i]);
		}
		printf("%d\n",solve(0,100000));
	}
}