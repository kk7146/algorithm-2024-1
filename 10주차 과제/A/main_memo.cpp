#include <algorithm>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

bool	can_sum(vector<int> array, int goal, vector<int>& memo)
{
	if (goal == 0)
		return (true);
	else if (goal < 0)
		return (false);
	if (memo[goal - 1] != -1)
		return memo[goal - 1];
	for (size_t i = 0; i < array.size(); i++)
		if (can_sum(array, goal - array[i], memo))
		{
			memo[goal - 1] = true;
			return (true);
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
		int			goal, len;
		cin >> goal;
		cin >> len;
		vector<int>memo (goal, -1);
		array = input_array(len);
		if (can_sum(array, goal, memo))
			cout << "true\n";
		else
			cout << "false\n";
	}
}
