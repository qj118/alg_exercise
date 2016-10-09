#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 10010;
int n,w[MAXN];

struct Mission{
	int l,r,w,i;
	bool operator < (const Mission &a) const
	{
		return r > a.r;//min_priority_queue
	}
}p[MAXN];

bool cmp(Mission a,Mission b)
{
	if(a.l == b.l)
		return a.r < b.r;
	return a.l < b.l;
}

bool check(int mid)
{
	Mission f;
	int mtime = 0,i = 0,tmid;
	priority_queue<Mission> Q;
	for(int i = 0;i < n;i++)
	{
		w[p[i].i] = p[i].w;
	}
	while(1)
	{
		while(i < n &&p[i].l <= mtime)
			Q.push(p[i++]);
		tmid = mid;
		while(Q.size() && tmid != 0)
		{
			f = Q.top();
			if(mtime >= f.r)
				return 0;
			w[f.i] -= tmid;
			if(w[f.i] > 0)
			{
				tmid = 0;
			}else
			{
				tmid -= w[f.i];
				Q.pop();
			}
		}
		if(i == n && (Q.size() == 0))
			break;
		mtime ++;
	}
	return 1;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i = 0;i < n;i++)
		{
			scanf("%d%d%d",&p[i].l,&p[i].r,&p[i].w);
			p[i].i = i;
			w[i] = p[i].w;
		}
		sort(p,p+n,cmp);
		int l = 1,r = 5000,mid;
		while(l <= r)
		{
			mid = (l + r)/2;
			if(check(mid)) r = mid - 1;
			else
				l = mid + 1;
		}
		printf("%d\n",l);
	}
	return 0;
}