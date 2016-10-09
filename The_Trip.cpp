#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int maxn = 10010;
int a[maxn],N,K,r[maxn],num[maxn],first[maxn],next[maxn],v[maxn];

int cmp(const void *_p,const void *_q)
{
	int *p = (int*)_p;
	int *q = (int*)_q;
	return *p - *q;
}

void init()
{
	int i,k;
	for(i = 0;i < N;i++)
	{
		scanf("%d",&a[i]);
	}
	qsort(a,N,sizeof(a[0]),cmp);
	r[0] = -1;
	k = 0;
	for(i = 0;i < N;i++)
	{
		if(a[i] == r[k])
			++num[k];
		else
		{
			++k;
			num[k] = 1;
			r[k] = a[i];
		}
	}
	K = k;
}

void solve()
{
	int i,j,k,ans[maxn],e;
	memset(first,-1,sizeof(first));
	e = k = 0;
	for(i = 1;i <= K;i++)
	{
		if(num[i] > k)
			k = num[i];
	}
	i = 0;
	for(j = 1; j <= K;j++)
	{
		while(num[j])
		{
			--num[j];
			v[e] = r[j];
			next[e] = first[i];
			first[i] = e;
			e++;
			i = (i + 1) % k;
		}
	}
	printf("%d\n",k);
	for(i = 0;i < k;i++)
	{
		int count  = 0;
		j = first[i];
		//printf("%d",v[j]);
		ans[count++] = v[j];
		for(j = next[j];j != -1;j = next[j])
			//printf(" %d",v[j]);
			ans[count++] = v[j];
		for(int s = count - 1;s >= 0;s--)
		{
			printf("%d ",ans[s]);
		}
		printf("\n");
	}
}

int main()
{
	int t = 0;
	for(;;)
	{
		scanf("%d",&N);
		if(!N)
			break;
		init();
		if(t++)
		{
			printf("\n");
		}
		solve();
	}
	return 0;
}