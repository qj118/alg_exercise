#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 5010;
const double eps = 0.00000001;
int n;
struct Target{
	int l,r,y;
}targets[maxn];

bool cmp(Target a,Target b)
{
	return a.y < b.y;
}

int judge(double mid)
{
	long double minL = (targets[0].l - mid)/targets[0].y;
	long double maxR = (targets[0].r - mid)/targets[0].y;
	for(int i = 1;i < n;i++)
	{
		long double L = (targets[i].l - mid)/targets[i].y;
	    long double R = (targets[i].r - mid)/targets[i].y;
	    if(maxR < L) return 1;
	    if(R < minL) return -1;
	    maxR = min(R,maxR);
	    minL = max(L,minL);
	}
	return 0;
}

int main()
{
	int T,w;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&w,&n);
		memset(targets,0,sizeof(targets));
		for(int i = 0;i < n;i++)
		{
			scanf("%d%d%d",&targets[i].y,&targets[i].l,&targets[i].r);
		}
		sort(targets,targets+n,cmp);
		long double left = 0,right = w,mid;
		bool flag = false;
		while(right - left > eps)
		{
			mid = (right - left)/2 + left;
			if(judge(mid) == 0)
			{
				flag = true;
				break;
			}
			else if(judge(mid) == -1)
				left = mid;
			else
				right = mid;
		}
		if(!flag)
		{
			printf("No\n");
		}
		else
			printf("Yes\n");
	}
	return 0;
}