#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 110;
char en[MAXN],de[MAXN];
int visit_en[MAXN],visit_de[MAXN];//save letter's number in the string
vector<char> en_1,de_1;//save no repeat letter

int main()
{
	int visit[MAXN];
	memset(visit,1,sizeof(visit));
	scanf("%s%s",en,de);
	//disadvantage:have a lot repeat code
	for(int i = 0;i < strlen(en);i++)
	{
		int flag = 1;
		for(int j = 0;j < en_1.size();j++)
		{
			if(en_1[j] == en[i])
			{
				flag = 0;
				visit_en[j]++;
				break;
			}
		}
		if(flag)
		{
			en_1.push_back(en[i]);
		}
	}
	for(int i = 0;i < strlen(de);i++)
	{
		int flag = 1;
		for(int j = 0;j < de_1.size();j++)
		{
			if(de_1[j] == de[i])
			{
				flag = 0;
				visit_de[j]++;
				break;
			}
		}
		if(flag)
		{
			de_1.push_back(de[i]);
		}
	}
	if(en_1.size() != de_1.size())
		printf("NO\n");
	else
	{
		int flag = 1;
		int n = en_1.size();
		sort(visit_en,visit_en+n);
		sort(visit_de,visit_de+n);
		for(int i = 0;i < n;i++)
		{
			if(visit_en[i] != visit_de[i])
			{
				printf("NO\n");
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			printf("YES\n");
		}
	}
	return 0;
}