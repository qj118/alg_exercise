#include <stdio.h>
const int MAXN = 10000;
int A[MAXN];

int bsearch(int* A,int x,int y,int v)
{
	int m;
	while(x < y)
	{
		m = x + (y-x)/2;
		if(A[m] == v)
			return m;
		else if(A[m] > v) y = m;
		else x = m+1;
	}
	return -1;
}

int low_bound(int *A,int x,int y,int v)
{
	int m;
	while(x < y)
	{
		m = x + (y-x)/2;
		if(A[m] >= v) y = m;
		else x = m + 1;
	}
	return x;
}

int upper_bound(int *A,int x,int y,int v)
{
	int m;
	while(x < y)
	{
		m = x + (y-x)/2;
		if(A[m] <= v) x = m + 1;
		else y = m;
	}
	return x;
}

int main()
{
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&A[i]);
	}
	for(int i = 0;i < m;i++)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",upper_bound(A,0,n,b) - low_bound(A,0,n,a));
	}
	return 0;
}