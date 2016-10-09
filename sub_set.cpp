#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAXN = 1000;
int A[MAXN];
int B[MAXN];

void print_subset_1(int n,int* A,int cur)
{
	for(int i = 0;i < cur;i++)
	{
		printf("%d",A[i]);
	}
	printf("\n");
	int s = cur ? A[cur-1]+1 : 0;
	for(int i = s;i < n;i++)
	{
		A[cur] = i;
		print_subset_1(n,A,cur + 1);
	}
}

void print_subset_2(int n,int *B,int cur)
{
	if(cur == n)
	{
		for(int i = 0;i < n;i++)
		{
			if(B[i]) printf("%d",i);
		}
		printf("\n");
		return;
	}
	B[cur] = 1;
	print_subset_2(n,B,cur + 1);
	B[cur] = 0;
	print_subset_2(n,B,cur + 1);
}

int main()
{
	int n;
	memset(B,0,sizeof(B));
	scanf("%d",&n);
	print_subset_1(n,A,0);
	print_subset_2(n,B,0);
	return 0;
}