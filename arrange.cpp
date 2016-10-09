#include <stdio.h>
#include <stdlib.h>
const int MAXN = 100000;
int A[MAXN];

void print_permutation(int n,int *A,int cur)
{
	int i,j;
	if(cur == n) //print
	{
		for(i = 0;i < n;i++)
		{
			printf("%d",A[i]);
		}
		printf("\n");
	}
	else
	{
		for(i = 1;i <= n;i++)
		{
			int ok = 1;
			for(j = 0;j < cur;j++)
			{
				if(A[j] == i) 
					ok = 0;
			}
			if(ok)
			{
				A[cur] = i;
				print_permutation(n,A,cur + 1);
			}
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
    print_permutation(n,A,0);
    return 0;
}