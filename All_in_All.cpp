#include <cstdio>
#include <cstring>

bool process(char s[],char t[])
{
	int i,j,jstart = 0;
	for(i = 0;i < strlen(s);i++)
	{
		for(j = jstart;j < strlen(t);j++)
		{
			if(t[j] == s[i])
			{
				jstart = j;
				break;
			}
		}
		if(j >= strlen(t))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	char s[100],t[100];
	while(scanf("%s%s",s,t))
	{
		if(process(s,t))
		{
			printf("Yes\n");
		}
		else
			printf("No\n");
	}
	return 0;
}