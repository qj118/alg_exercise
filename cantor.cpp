#include <stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n) == 1)
	{
		int i = 1,s = 0;
		while (s < n)
		{
			s = 0.5 * i * (i+1);
			i++;
		}
		i = i-1;
	    if(i % 2 == 0) printf("%d/%d",i - s + n,s - n + 1);
	    else printf("%d/%d",s - n + 1,i - s + n);
	    printf("\n");
	}
	return 0;
}