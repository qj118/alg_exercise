#include <cstdio>
using namespace std;

const int maxn = 100;
int winning[maxn][maxn];
int main()
{
	winning[1][1] = false;
	for(int k = 3;k < 20;k++)
	{
		for(int n = 1;n < k;n++)
		{
			int m = k - n;
			winning[n][m] = false;
			for(int i = 1;i < n;i++)
			{
				if(!winning[i][n - i]) winning[n][m] = true;
			}
			for(int i = 1;i < m;i++)
			{
				if(!winning[i][m - i]) winning[n][m] = true;
			}
			if(n <= m && !winning[n][m])
				printf("%d %d\n",n,m);
		}
	}
	return 0;
}