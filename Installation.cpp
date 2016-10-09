#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 510;
const int INF = 100007;
int sum_time,n,vis[maxn];

struct Job{
	int s;
	int d;
	int p;
}jobs[maxn];

int cmp(Job a,Job b)
{
	if(a.d != b.d)
		return a.d < b.d;
	else
		return a.s < b.s;
}

int cmpp(Job a,Job b)
{
	return a.p < b.p;
}

void init()
{
	memset(vis,0,sizeof(vis));
	for(int i = 0;i < n;i++)
	{
		scanf("%d%d",&jobs[i].s,&jobs[i].d);
	}
	sort(jobs,jobs + n,cmp);
}

void solve()
{
	sum_time = jobs[0].s;
	vis[0] = 1;
	jobs[0].d = max(0,sum_time - jobs[0].d);
	while(true)
	{
		bool flag = false;
		bool zflag = true;
		int min = INF,mini;
		for(int i = 1;i < n;i++)
		{
			if(!vis[i])
			{
				flag = true;
				int temp = max(0,sum_time + jobs[i].s - jobs[i].d);
				if(temp == 0 && zflag)
				{
					mini = i;
					break;
				}
				else if(temp == 0 && !zflag)
					break;
				if(min > temp)
				{ 
					zflag = false;
					min = temp;
					mini = i;
				}
			}
		}
		if(flag)
		{
			vis[mini] = 1;
			sum_time += jobs[mini].s;
			jobs[mini].p = max(0,sum_time - jobs[mini].d);
		}
		else
			break;
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		init();
		solve();
		sort(jobs,jobs + n,cmpp);
		printf("%d\n",jobs[n-1].p + jobs[n-2].p);
	}
	return 0;
}