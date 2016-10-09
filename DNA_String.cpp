#include <cstdio>
#include <cstring>
const int MAXN = 1010;
const int MAXM = 60;
int m,n;
char a[MAXM][MAXN],ch[4] = {'A','C','G','T'};

int process(int i)
{
	int h[4] = {0},max = -1,maxj = 0;
	for(int j = 0;j < m;j++)
	{
		if(a[j][i] == 'A')
			h[0]++;
		if(a[j][i] == 'C')
			h[1]++;
		if(a[j][i] == 'G')
			h[2]++;
		if(a[j][i] == 'T')
			h[3]++;
	}
	for(int j = 0;j < 4;j++)
	{
		if (h[j] > max)
		{
			max = h[j];
			maxj = j;
		}
	}
	printf("%c",ch[maxj]);
	return m - max; 
}

int main()
{
	scanf("%d%d",&m,&n);
	for(int i  = 0;i < m;i++)
	{
		scanf("%s",a[i]);
	}
	int answer = 0;
	for(int i = 0;i < n;i++)
	{
		answer += process(i);
	}
	printf("\n%d\n",answer);
	return 0;
}