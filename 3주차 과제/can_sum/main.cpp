#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

bool	can_sum(vector<int> array, int goal)
{
	if (goal == 0)
		return (true);
	else if (goal < 0)
		return (false);
	for (size_t i = 0; i < array.size(); i++)
		if (can_sum(array, goal - array[i]))
			return (true);
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

	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		cin >> goal;
		cin >> len;
		array = input_array(len);
		if (can_sum(array, goal))
			cout << "true\n";
		else
			cout << "false\n";
	}
}
