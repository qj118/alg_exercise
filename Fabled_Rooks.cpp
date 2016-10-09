#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 5010;
const int INF = 0x3f3f3f3f;

int N,D,tree[4 * maxn],di[2 * maxn],x[maxn],y[maxn];
struct A
{
	int x1,x2,y1,y2;
}a[maxn];

int get(int id)
{
	return id > 0 ? a[id].x1 : a[-id].x2 + 1;
}

bool cmp(const int x,const int y)
{
	return get(x) < get(y);
}

void input()
{
	for(int i = 1;i <= N;i++)
	{
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		di[2*i -2] = i;
		di[2*i - 1] = -i;
	}
	for(D = 1;D < N+2;D <<= 1);
    a[0].x2 = INF;
    memset(tree,0,sizeof(tree[0]) *  2 * D);
}

void update(int i)//update the small top of the heap
{
	for(;i ^ 1;i >>= 1) tree[i >> 1] = a[tree[i]].x2 < a[tree[i^1]].x2 ? tree[i] : tree[i^1];//choose the smallest endline
}

void deal(int x[maxn])
{
	sort(di,di + 2*N,cmp);//sort start and end together
	int cur = 0;
	for(int i = 1;i <= N+1;i++)
	{
		while(cur < 2*N)
		{
			int id = di[cur];
			if(get(id) != i) break;
			if(id > 0)
			{
				tree[D + id] = id;
				update(D+id);
			}
			else
			{
				tree[D - id] = 0;
				update(D-id);
			}
			++cur;
		}
		int id = tree[1];
		if(id == 0) continue;
		x[id] = i;
		tree[D+id] = 0;
		update(D+id);
	}
}

void process()
{
	memset(x,0,sizeof(x[0]) * (N+1));
	memset(y,0,sizeof(y[0]) * (N+1));
	deal(x);
	for(int i = 1;i <= N;i++)
	{
		swap(a[i].x1,a[i].y1);
		swap(a[i].x2,a[i].y2);
	}
	deal(y);
	for(int i = 1;i <= N;i++)
	{
		if(x[i] == 0 || y[i] == 0)
		{
			printf("IMPOSSIBLE\n");
			return;
		}
	}
	for(int i = 1;i <= N;i++)
	{
		printf("%d %d\n",x[i],y[i]);
	}
}

int main()
{
	while(scanf("%d",&N) == 1 && N)
	{
		input();
		process();
	}
	return 0;
}