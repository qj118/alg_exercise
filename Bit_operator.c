#include <stdio.h>

int setbits(int x, int p, int n, int y)
{
	// int r = x & ~(~0 << (p - n));
	// y = y & ~(~0 << n);
	// return ((((x >> p) << n) | y) << (p-n)) | r;
	return x & ((~(~0 << (p - n))) | (~0 << p)) | ((y & ~(~0 << n)) << (p-n));
}

int invert(int x, int p, int n)
{
	int r = x & ~(~0 << (p - n));
	int y = (~(x >> (p - n)) & ~(~0 << n)) & ~(~0 << n);
	return ((((x >> p) << n) | y) << (p-n)) | r;
}

int rightrot(int x, int n)
{
	int r = x & ~(~0 << n);
	int y = x, count = 0;
	while(y)
	{
		count ++;
		y >>= 1;
	}
	return (x >> n) | (r << (count - n));
}

int main()
{
	int x = 15, p = 3, n = 2, y = 5;
	printf("%d\n",setbits(x, p, n, y));
	printf("%d\n",invert(x,p,n));
	printf("%d\n",rightrot(y,n));
	return 0;
}
