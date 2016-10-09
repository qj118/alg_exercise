#include <cstdio>

int main(){
	int m,n,ans;
	while(scanf("%d%d",&m,&n) == 2 && m && n)
	{
		ans = (m - 1) + m * (n-1);
		printf("%d\n",ans);
	}
	return 0;
}