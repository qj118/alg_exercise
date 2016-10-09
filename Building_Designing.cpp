#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 500010;
int pos[maxn],neg[maxn];

int func(int* min,int* max,int mn,int mx)
{
	int ans  = 0;
	for(int i = 0;i < mn;i++)
	{
		for(int j = 0;j < mx;j++)
		{
			if(i == 0)
			{
				if(abs(max[j]) < abs(min[i]))
				{
					ans++;
					break;
				}
			}
			else
			{
				if(abs(max[j]) > abs(min[i-1]) && abs(max[j]) < abs(min[i]))
				{
					ans += 2;
					break;
				}
			}
		}
	}
	for(int j = 0;j < mx;j++)
	{
	    if(abs(max[j]) > abs(min[mn-1]))
	    {
			ans += 2;
		    break;
		}			       
	}
	return ans;
}

int comp(int a,int b)
{
	if(a > b)
		return 1;
	else 
		return 0;
}

int main()
{
	int T,n,ans;
	scanf("%d",&T);
	while(T--)
	{
		int po = 0, ne = 0,temp;
		memset(pos,0,sizeof(pos));
		memset(neg,0,sizeof(neg));
		scanf("%d",&n);
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&temp);
			if(temp < 0) neg[ne++] = temp;
			else
				pos[po++] = temp;
		}
		sort(pos,pos+po);
		sort(neg,neg+ne,comp);
		if(po >= ne)
		{
			ans = func(neg,pos,ne,po);
		}
		else
		{
			ans = func(pos,neg,po,ne);
		}
		printf("%d\n",ans);
	}
	return 0;
}