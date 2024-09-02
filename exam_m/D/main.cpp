#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int BFS()
{
	queue<int> q;
	while (q.empty())
	{
		/* code */
	}
	
}

int main()
{
	int testcase;

	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		int N, buf;
		cin >> N;
		vector<vector<int> > map;
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				cin >> buf;
				map[i].push_back(buf);
			}
		}
	}
	return 1;
}