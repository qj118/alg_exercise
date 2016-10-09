#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 4;
int n,dice[maxn][6],ans,dice24[24][6];

int left[] = {4,0,2,3,5,1};
int up[] = {2,1,5,0,4,3};
void rot(int *T,int *p)
{
	int q[6];
	memcpy(q,p,sizeof(q));
	for(int i = 0;i < 6;i++)
	{
		p[i] = T[q[i]];
	}
}
void enumerate_permutations()
{
	int p0[6] = {0,1,2,3,4,5};
	int a = 0;
	for(int i = 0;i < 6;i++)
	{
		int p[6];
		memcpy(p,p0,sizeof(p0));
		if(i == 0) rot(up,p);
		if(i == 1) {rot(left,p),rot(up,p);}
		if(i == 3) {rot(up,p);rot(up,p);}
		if(i == 4) {rot(left,p);rot(left,p);rot(left,p);rot(up,p);}
		if(i == 5) {rot(left,p);rot(left,p);rot(up,p);}
		for(int j = 0;j < 4;j++)
		{
			for(int k = 0;k < 6;k++)
			{
				dice24[a][k] = p[k];
			}
			a++;
			rot(left,p);
		}
	}
}

vector<string> names;
int ID(const char* name)
{
	string s(name);
	int n = names.size();
	for(int i = 0;i < n;i++)
	{
		if(names[i] == s) return i;
	}
	names.push_back(s);
	return n;
}

int r[maxn],color[maxn][6];

void check()
{
	enumerate_permutations();
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < 6;j++)
		{
			color[i][dice24[r[i]][j]] = dice[i][j];
		}
	}
	int tot = 0;
	for(int j = 0;j < 6;j++)
	{
		int cnt[maxn*6];
		memset(cnt,0,sizeof(cnt));
		int maxface = 0;
		for(int i = 0;i < n;i++)
		{
			maxface = max(maxface,++cnt[color[i][j]]);
		}
		tot += n - maxface;
	}
	ans = min(ans,tot);
}

void dfs(int d)
{
	if(d == n)
		check();
	else for(int i = 0;i < 24;i++)
	{
		r[d] = i;
		dfs(d+1);
	}
}

int main()
{
	while(scanf("%d",&n) == 1 && n)
	{
		names.clear();
		for(int i = 0;i < n;i++)
		{
			for(int j =0;j < 6;j++)
			{
				char name[30];
				scanf("%s",name);
				dice[i][j] = ID(name);
			}
		}
		ans = n * 6;
		r[0] = 0;
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}