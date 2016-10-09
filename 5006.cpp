#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 100;

int m,n,A[MAXN],B[MAXN];

int f(int a,int b)
{
	int c = a^b;
	int count = 0,i = 1;
	while(c)
	{
		if(c & i)
		{
			count++;
		}
		c >>= 1;
	}
	return count;
}

void min(int x)
{
	int min = 1000000, mini = 0;
	for(int i = 0;i < m; i++)
	{
		int count = f(A[i],x);
		if(min > count)
		{
			mini = i;
			min = count;
		}else if(min == count)
		{
			if(A[i] < A[mini])
			{
				mini = i;
			}
		}
	}
	printf("%d\n",A[mini]);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&m,&n);
		for(int i = 0;i < m;i ++)
		{
			scanf("%d",&A[i]);
		}
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&B[i]);
		}
		for(int i = 0; i < n;i++)
		{
			min(B[i]);
		}
	}
	return 0;
}