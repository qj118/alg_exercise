#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 60;

struct  Game{
	int number;
	friend bool operator <(const Game a,const Game b)
	{
		int n = a.number;
		int m = b.number;
		int i = 0,j = 0;
	    while(i == j)
	    {
	      int x = n,y = m;
	      int ntime = 0,mtime = 0;
	      while(x){
	    	i = x % 10;
	    	x /= 10;
	       	ntime++;
	       }
	       while(y){
	    	  j = y % 10;
	    	  y /= 10;
	    	  mtime++;
	       }
	       if(i == j)
	       {
	       	  int  p = 1,q = 1;
	       	  if(ntime == 1 && mtime == 1)
	       	  {
	       	  	return 0;
	       	  }
	       	  while (--ntime)
	       	  {
	       	  	 p *= 10;
	       	  }
	       	  while (--mtime)
	       	  {
	       	  	q *= 10;
	       	  }
	       	  m = m % p;
	       	  n = n % q;
	       }
	    }
	    return i < j;
	}
	
}arr[MAXN];



int main(){
	int n;
	
	while(scanf("%d",&n) == 1 && n)
	{
	    for(int i = 0;i < n;i++)
	    {
	    	scanf("%d",&arr[i].number);
	    }
	    sort(arr,arr + n);
	    for(int i = n-1;i >= 0;i--)
	    {
	    	printf("%d",arr[i].number);
	    }
	    printf("\n");
    }
	return 0;
}