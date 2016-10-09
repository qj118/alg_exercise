#include <cstdio>
#include <string>
using namespace std;
const int MAXN = 500000;
int left[MAXN],right[MAXN];
void Link(int x,int y)
{
	right[x] = y;
	left[y] = x; 
}
int main()
{
	int n,m,x,y;
	char type[10];
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
	{
		left[i] = i-1;
		right[i-1] = i;
	}
	right[n] = n + 1;
	for(int i = 1;i <= m;i++)
	{
		printf("input instruction:");
		//type = 'A';
		scanf("%s%d%d",&type,&x,&y);
		Link(left[x],right[x]);
		if(type[0] == 'A')
		{
			Link(left[y],x);
			Link(x,y);
		}
		else
		{
			Link(x,right[y]);
			Link(y,x);
		}
	}
	for(int i = 0;i < n+1;i = right[i])
	{
		printf("%d" ,right[i]);
	}
	return 0;
}