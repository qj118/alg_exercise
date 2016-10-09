#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 210;
int t,out[N],on,len,sg[N];
char str[N];

bool win()
{
	for(int i = 0;i < len - 2;i++)
	{
		if(str[i] == 'X' && str[i+1] == 'X' && str[i + 2] == 'X')
			return true;
	}
	return false;
}

int mex(int x)
{
	bool vis[N];
	int i,t;
	if(sg[x] != -1)
		return sg[x];
	if(x == 0)
		return sg[x] = 0;
	memset(vis,false,sizeof(vis));
	for(int i = 1;i <= x;i++)
	{
		int t = mex(max(0,i - 3)) ^ mex(max(0, x - i - 2));
		vis[t] = true;
	}
	for(int i = 0;i < N;i++)
	{
		if(vis[i])
			continue;
		return sg[x] = i;
	}
}

bool towin()
{
	for(int i = 0;i < len;i++)
	{
		if(str[i] == '.')
		{
			str[i] = 'X';
			if(win())
			{
				str[i] = '.';
				return false;
			}
			str[i] = '.';
		}	
	}
	int ans = 0,num = 0;
	for(int i = 0;i < len;i++)
	{
		if(str[i] == 'X' || (i >= 1 && str[i - 1] == 'X') || (i >= 2) && str[i - 2] == 'X' || (i + 1 < len && str[i + 1] == 'X') || (i + 2 < len && str[i + 2] == 'X'))
		{
			ans ^= mex(num);
			num = 0;
		}
		else
			num++;
	}
	ans ^= mex(num);
	return ans == 0;
}

void solve(){
	on = 0;
	len = strlen(str);
	for(int i = 0;i < len;i++)
	{
		if(str[i] != '.')
			continue;
		str[i] = 'X';
		if(win() || towin())
			out[on++] = i + 1;
		str[i] = '.';
	}
}

int main()
{
	memset(sg,-1,sizeof(sg));
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str);
		solve();
		if(on == 0)
			printf("Losing\n\n");
		else{
			printf("Win\n%d",out[0]);
			for(int i = 1;i < on;i++)
			{
				printf("%d ",out[i]);
			}
			printf("\n");
		}
	}
	return 0;
}