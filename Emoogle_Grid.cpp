#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef long long LL;
const int MOD = 100000007;
const int maxb = 510;
int n,m,k,b,r,x[maxb],y[maxb];
set< pair<int,int> > bset;

LL gcd(LL a,LL b,LL &d,LL &x,LL &y)
{
	if(!b)
	{
		d = a;
		x = 1;
		y = 0;
	}
	else
	{
		gcd(b,a % b,d,y,x);
		y -= x*(a/b);
	}
}

LL mul_mod(LL a,LL b)
{
	return a * b % MOD;
}

LL pow_mod(LL a,LL p)
{
	if(p == 0) return 1;
	LL ans = pow_mod(a,p/2);
	ans = ans * ans % MOD;
	if(p % 2 == 1)
		ans = ans * a % MOD;
	return ans;
}

LL inv(LL a)
{
	LL d,x,y;
	gcd(a,MOD,d,x,y);
	return d == 1?(x + MOD) % MOD : -1;
}

int log_mod(int a,int b)
{
	int m,v,e = 1,i;
	m = (int)sqrt(MOD + 0.5);
	v = inv(pow_mod(a,m));
	map<int,int> x;
	x[1] = 0;
	for(i = 1;i < m;i++)
	{
		e = mul_mod(e,a);
		if(!x.count(e))
			x[e] = i;
	}
	for(i = 0;i < m;i++)
	{
		if(x.count(b))
			return i*m + x[b];
		b = mul_mod(b,v);
	}
	return -1;
}

int count()
{
	int c = 0;
	for(int i = 0;i < b;i++)
	{
		if(x[i] != m && !bset.count(make_pair(x[i] + 1,y[i])))
			c++;
	}
	c += n;
	for(int i = 0;i < b;i++)
	{
		if(x[i] == 1)
			c--;
	}
	//printf("c = %d\n",c);
	return mul_mod(pow_mod(k,c),pow_mod(k-1,(LL)m*n-b-c));
}

int doit()
{
	int cnt = count();
	printf("cnt = %d\n",cnt);
	if(cnt == r)
	{
		return m;
	}
	int c = 0;
	for(int i = 0;i < b;i++)
	{
		if(x[i] == m)
			c++;
	}
	//printf("c = %d\n",c);
	m++;
	//printf("m = %d\n",m);
	cnt = mul_mod(cnt,pow_mod(k,c));
	//printf("cnt = %d\n",cnt);
	cnt = mul_mod(cnt,pow_mod(k-1,n-c));
	//printf("cnt = %d\n",cnt);
	if(cnt == r)  return m;
	//printf("m = %d\n",log_mod(pow_mod(k-1,n),mul_mod(r,inv(cnt))));
	return log_mod(pow_mod(k-1,n),mul_mod(r,inv(cnt))) + m;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int t = 1;t <= T;t++)
	{
		scanf("%d%d%d%d",&n,&k,&b,&r);
		bset.clear();
		m = 1;
		for(int i = 0;i < b;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
			if(x[i] > m) m = x[i];
			bset.insert(make_pair(x[i],y[i]));
		}
		printf("Case %d: %d\n",t,doit());
	}
	return 0;
}