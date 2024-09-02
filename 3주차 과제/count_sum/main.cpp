#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

void	can_sum(vector<int> array, int *count, int goal)
{
	if (goal == 0)
		(*count)++;
	else if (goal < 0)
		return ;
	for (size_t i = 0; i < array.size(); i++)
		can_sum(array, count ,goal - array[i]);
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
	int			count;

	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		count = 0;
		cin >> goal;
		cin >> len;
		array = input_array(len);
		can_sum(array, &count, goal);
		cout << count << '\n';
	}
}
