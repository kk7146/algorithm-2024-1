#include <algorithm>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

bool isVisited(int index, vector<int> visited)
{
	for (size_t i = 0; i < visited.size(); i++)
	{
		if (visited[i] == index)
			return true;
	}
	return false;
}

bool	can_sum(vector<int> array, int goal, vector<int>& memo, vector<int>& visited)
{
	if (goal == 0)
		return (true);
	else if (goal < 0)
		return (false);
	if (memo[goal - 1] != -1)
		return memo[goal - 1];
	for (int i = 0; i < array.size(); i++)
		if (!isVisited(i, visited))
		{
			visited.push_back(i);
			if (can_sum(array, goal - array[i], memo, visited))
			{
				memo[goal - 1] = true;
				visited.pop_back();
				return (true);
			}
			visited.pop_back();
		}
	memo[goal - 1] = false;
	return (false);
}

vector<int>	input_array(size_t len)
{
	vector<int> new_array(len);

	for (size_t i = 0; i < len; i++)
		cin >> new_array[i];
	return (new_array);
}

int	main()
{
	size_t		T;
	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		vector<int> array;
		vector<int> visited;
		int	len, sum = 0;
		cin >> len;
		array = input_array(len);
		for (size_t i = 0; i < len; i++)
			sum += array[i];
		if (sum % 2 == 1)
		{
			cout << "false\n";
			continue;
		}
		vector<int>memo (sum, -1);
		if (can_sum(array, sum / 2, memo, visited))
			cout << "true\n";
		else
			cout << "false\n";
	}
}
