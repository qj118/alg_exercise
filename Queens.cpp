#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
vector<vector<int> > result;

bool conflict(vector<int> state, int nextX)
{
	int nextY = state.size();
	for(int i = 0; i < nextY; i++)
	{
		if(abs(state[i] - nextX) == 0 || abs(state[i] - nextX) == nextY - i)
		{
			return true;
		}
	}
	return false;
}

void queens(int num, vector<int> state)
{
	for(int i = 0; i < num; i++)
	{
		if(!conflict(state, i))
		{
			if(state.size() == num - 1)
			{
				state.push_back(i);
				result.push_back(state);
			}
			else
			{
				state.push_back(i);
				queens(num, state);
			}
		}
	}
}

int main()
{
	result.clear();
	vector<int> state;
	queens(4, state);
	printf("%d", result.size());
	for(int i = 0; i < result.size(); i++)
	{
		for(int j = 0; j < result[i].size(); j++)
		{
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}
