#include <cstdio>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 50 + 5;
const int maxi = 100000 + 10;

struct node
{
	int cur_status;
	set<int> scales;
};

int n,max_number,status;
int numbers[maxn],n_index[maxi];
set<int> ans;

void init()
{
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&numbers[i]);
	}
	sort(numbers,numbers + n);
	n = unique(numbers,numbers + n) - numbers;
	max_number = numbers[n-1];
	ans.clear();
	ans.insert(0);
	memset(n_index,-1,sizeof(n_index));
	for(int i = 0;i < n;i++)
	{
		n_index[numbers[i]] = i;
		ans.insert(numbers[i]);
	}
	status = (1 << n) - 1;
}

bool check_scale(int scale,node cur)
{
	if(cur.scales.find(scale) != cur.scales.end())
		return false;
	if(scale < 0 || scale > max_number)
		return false;
	return true;
}

void add_node(int scale,node cur,queue<node>& q)
{
	node new_node = cur;
	new_node.scales.insert(scale);
	for(set<int>::iterator iter = cur.scales.begin();iter != cur.scales.end();iter++)
	{
		int number = abs(scale - *iter);
		if(n_index[number] != -1)
			new_node.cur_status |= 1 << n_index[number];
	}
	if(new_node.cur_status != cur.cur_status)
		q.push(new_node);
}

void scan_and_add_node(int scale,node cur,queue<node>& q)
{
	for(int i = 0;i < n;++i)
	{
		if(cur.cur_status & (1 << i))
			continue;
		if(check_scale(scale - numbers[i],cur))
			add_node(scale - numbers[i],cur,q);
		if(check_scale(scale + numbers[i],cur))
			add_node(scale + numbers[i],cur,q);
	}
}

void bfs()
{
	node init_node;
	init_node.cur_status = 0;
	init_node.scales.insert(0);
	queue<node> q;
	q.push(init_node);
	while(!q.empty())
	{
		node top = q.front();
		q.pop();
		if(top.cur_status == status)
		{
			if(top.scales.size() < ans.size())
			{
				ans = top.scales;
			}
			else if(top.scales.size() == ans.size() && *top.scales.rbegin() < *ans.rbegin())
				ans = top.scales;
			return;
		}
		for(set<int>::iterator iter = top.scales.begin();iter != top.scales.end();++iter)
			scan_and_add_node(*iter,top,q);
	}
}

void output()
{
	printf("%d\n",ans.size());
	for(set<int>::iterator iter = ans.begin();iter != ans.end();iter++)
	{
		printf("%d ",*iter);
	}
	printf("\n");
}

int main()
{
	int kase = 0;
	while(scanf("%d",&n) && n != 0)
	{
		init();
		bfs();
		printf("Case %d:\n",++kase);
		output();
	}
	return 0;
}