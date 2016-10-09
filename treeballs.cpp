#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	int D,I;
	while((scanf("%d%d",&D,&I)) == 2)
	{
		int k = 1,n = (1<<(D-1));
		while(k <= n)
		{
			if(I % 2 == 0)
			{
				k = k*2 + 1;
				I = I / 2;
			}
			else
			{
				k = k*2;
				I = (I + 1)/2;
			}
		}
		printf("%d\n",k);
	}
	return 0;
}