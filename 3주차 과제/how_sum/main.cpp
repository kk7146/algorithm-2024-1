#include <algorithm>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

bool	can_sum(vector<int> array, vector<int> *result,int goal, vector<int>& memo)
{
	if (goal == 0)
		return (true);
	else if (goal < 0)
		return (false);
    if (memo[goal - 1] != -1)
		return memo[goal - 1];
	for (size_t i = 0; i < array.size(); i++)
	{
		if (can_sum(array, result ,goal - array[i], memo))
		{
			(*result).push_back(array[i]);
            memo[goal - 1] = true;
			return (true);
		}
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
	size_t		T, len;
	int			goal;
	vector<int> array;
	vector<int> result;

	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		cin >> goal;
		cin >> len;
		array = input_array(len);
		vector<int>memo (goal, -1);
		if (can_sum(array, &result, goal, memo))
		{
			cout << result.size() << ' ';
			for (int i = result.size() - 1; 0 <= i; i--)
				cout << result[i] << ' ';
		}
		else
			cout << "-1";
		cout << "\n";
		result.clear();
	}
}
