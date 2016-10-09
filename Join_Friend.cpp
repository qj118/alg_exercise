#include <cstdio>
#include <cstring>
using namespace std;

int t;
int t1,t2,s1,s2,w;

double calculate(int w)
{
	int ly = t1 + w;
	int ry = t2 + w;
	int ux = s2 - w;
	int dx = s1 - w;

	if(ly >= s2) return 0;
	if(ry <= s1) return (t2 - t1) * (s2 - s1);
	bool isleft = (ly >= s1 && ly <= s2);
	bool isright = (ry >= s1 && ry <= s2);
	bool isup = (ux >= t1 && ux <= t2);
	bool isdown = (dx >= t1 && dx <= t2);
	if(isleft && isup)
		return (ux - t1) * (s2 - ly) * 0.5;
	if(isleft && isright)
		return (s2 - ly + s2 - ry) * (t2 - t1) * 0.5;
	if(isdown && isright)
		return (t2 - t1) * (s2 - s1) - (t2 - dx) * (ry - s1) * 0.5;
	if(isdown && isup)
		return (ux - t1 + dx - t1) * (s2 - s1) * 0.5;
}

int main()
{
	int cas = 0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d",&t1,&t2,&s1,&s2,&w);
		printf("Case #%d: %.7lf\n",++cas,(calculate(-w) - calculate(w))/((t2 - t1) *(s2 - s1)));
	}
	return 0;
}