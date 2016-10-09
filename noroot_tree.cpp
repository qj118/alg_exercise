#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1000000;
vector<int> G[maxn];
int p[maxn];

void read_tree(int n)
{
	int u,v;
	for(int i = 0;i < n-1;i++)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
}

void dfs(int u,int fa)
{
	int d = G[u].size();
	for(int i = 0;i < d;i++)
	{
		int v  = G[u][i];
		if(v != fa)
			dfs(v,p[v] = u);
	}
}

int main()
{
	int n,root;
	scanf("%d%d",&n,&root);
	memset(p,-2,sizeof(p));
	p[root] = -1;
	read_tree(n);
	dfs(root,p[root]);
	for(int i = 0;i < n;i++)
	{
		printf("%d ",p[i]);
	}
	printf("\n");
	return 0;
}