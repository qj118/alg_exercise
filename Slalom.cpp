#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 100010;
int W,vh,N;

struct Gate{
	int x,y;
}g[maxn];

void input()
{
	scanf("%d%d%d",&W,&vh,&N);
	for(int i = 0;i < N;i++)
	{
		scanf("%d%d",&g[i].x,&g[i].y);
	}
}

int check(int v)
{
	double x1 = g[0].x,x2 = g[0].x + W;
	for(int i = 1;i < N;i++)
	{
		double d = vh * (g[i].y - g[i-1].y)/v;
		x1 -= d;
		x2 += d;// (x2 - x1) is the max distants the sporter can reach in the speed.
		x1 = max(x1,(double)g[i].x);
		x2 = min(x2,(double)g[i].x + W);
		if(x1 > x2 + 1e-10) 
			return 0;// fast
	}
	return 1;//slow
}

void process()
{
	int min = 0,max = 100010,mid;
	while(true)
	{
	   mid = (max - min)/2 + min;
	   if(mid == min) break;
	   if(check(mid)) 
	   	   min = mid;
	   else
		   max = mid;
	}
	int s,ans = 0;
	scanf("%d",&s);
	for(int i = 0;i < s;i++)
	{
		int t;
		scanf("%d",&t);
		if(t <= mid)
			ans = std::max(t,ans);
	}
	if(ans == 0)
		printf("Impossible\n");
	else
		printf("%d\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		input();
		process();
	}
	return 0;
}