#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int const MAXN = 100 + 10;
int vis[MAXN][MAXN],maze[MAXN][MAXN],fa[MAXN][MAXN],dist[MAXN][MAXN],last_dir[MAXN][MAXN];
int q[MAXN * MAXN];
char name[4] = {'U','D','L','R'},s[MAXN];
int n,m;
int direc[MAXN*MAXN];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void bfs(int x,int y)
{
	int front = 0,rear = 0,d,u;
	u = x*m + y;
	vis[x][y] = 1;
	fa[x][y] = u;
	dist[x][y] = 0;
	q[rear++] = u;
	while(front < rear)
	{
		u = q[front++];
		x = u/m;
		y = u%m;
		for(d = 0;d < 4;d++)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			if(nx >= 0 && nx <n && ny >= 0 && ny < m && maze[nx][ny] && !vis[nx][ny])
			{
				int v = nx * m + ny;
				q[rear++] = v;
				vis[nx][ny] = 1;
				fa[nx][ny] = u;
				dist[nx][ny] = dist[x][y] + 1;
				last_dir[nx][ny] = d;
			}
		}
	}
}

void print_path(int x,int y)
{
	int c = 0;
	for(;;)
	{
		int fx = fa[x][y]/m;
		int fy = fa[x][y]%m;
		if(fx == x && fy == y) break;
		direc[c++] = last_dir[x][y];
		x = fx;
		y = fy;
	}
	while(c--)
	{
		putchar(name[direc[c]]);
	}
}

int main()
{
	memset(vis,0,sizeof(vis));
	memset(maze,0,sizeof(maze));
	memset(fa,0,sizeof(fa));
	memset(dist,0,sizeof(dist));
	memset(last_dir,0,sizeof(last_dir));
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n;i++)
	{
		scanf("%s",s);
		for(int j = 0;j < m;j++)
		{
			maze[i][j] = s[j] - '0';
		}
	}
	bfs(0,0);
	int max = 0,maxi = 0,maxj = 0;
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
		{
			if(max < dist[i][j])
			{
				max = dist[i][j];
			    maxi = i;
			    maxj = j;
			}
		}
	}
	print_path(maxi,maxj);
	printf("\n");
	return 0;
}