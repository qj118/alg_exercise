#include <cstdio>

int main()
{
	int g,l;
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&g,&l);
		if(l % g == 0)
		{
			printf("%d %d\n",g,l);
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}