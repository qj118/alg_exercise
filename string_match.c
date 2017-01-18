#include <stdio.h>
int match(char s1[], char s2[])
{
	int i, j, r = 0;
	for(r = 0; s1[r] != '\0'; r++)
	{
		for(i = r, j = 0; s2[j] != '\0'; i++, j++)
		{
			if(s1[i] != s2[j])
			{
				break;
			}
		}
		if(s2[j] == '\0')
		{
			break;
		}
	}
	if(s1[r] == '\0')
	{
		return -1;
	}
	return r;
}
