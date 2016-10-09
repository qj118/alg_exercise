#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 10010;
int n,index;
double l,w;

struct Node{
	double left;
	double right;
	friend bool operator <(const Node &a,const Node &b)
	{
		return a.left < b.left;
	}
}arr[MAXN];

int main()
{
	double p,r;
	while((scanf("%d%lf%lf",&n,&l,&w) == 3) && n)
	{
		index = 0;
		for(int i = 0;i < n;i++)
		{
			scanf("%lf%lf",&p,&r);
			if(w/2 >= r)
				continue;
			double t = sqrt(r*r - w*w/4.0);
			arr[index].left = p - t;
			arr[index].right = p + t;
			++index;
		}
		sort(arr,arr + index);
		double left = 0,right = 0;
		bool flag = false;
		int ans = 0;

		if(arr[0].left <= 0)
		{
			int i = 0;
			while(i < index)
			{
				int j = i;
				while(j < index && left >= arr[j].left)
				{
					if(arr[j].right > right)
						right = arr[j].right;
					j++;
				}
				if(i == j)
					break;
				++ans;
				left = right;
				i = j;

				if(left > l)
				{
					flag = true;
					break;
				}
			}
		}
		if(flag)
		{
			printf("%d\n",ans);
		}
		else
			printf("-1\n");
	}
	return 0;
}