#include <cstdio>
#include <algorithm>
using namespace std;

int const maxn = 1010;
int a[maxn],b[maxn];

int cmp(int a,int b)
{
	return a > b;
}

int main()
{
	int n;
	while(scanf("%d",&n) == 1 && n)
	{
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&b[i]);
		}
		sort(a,a+n,cmp);
		sort(a,a+n,cmp);
		int i = 0,j = 0,k = n-1,f = n-1;
		int sum = 0;
		int flag = 0;
		while(1)
		{
			if(flag == n)
				break;
			if(b[j] > a[i])
			{
				sum -= 200;
				j++;
				k--;
				flag++;
			}
			else if(b[j] == a[i])
			{
				if(b[f] < a[k])
				{
					f--;
					k--;
					sum += 200;
					flag++;
				}
				else if(b[f] > a[k])
				{
					sum -= 200;
					k --;
					j ++;
					flag++;
				}
				else
				{
					k--;
					f--;
					flag++;
				}
			}
			else
			{
				sum += 200;
				j++;
				i++;
				flag++;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}