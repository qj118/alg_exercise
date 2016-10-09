#include <stdio.h>
int f(int *q)
{
	int i = 0;
	for(;i < 5;i++)
		(*q)++;
}
int main()
{
	int a[5] = {1,2,3,4,5},i;
	f(a);
	for(int i = 0;i < 5;i++)
	{
		printf("%d,",a[i]);
	}
	return 0;
}