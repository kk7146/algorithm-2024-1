#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

int	acc(vector<int> array)
{
	int count = 0;

	for (size_t i = 0; i < array.size(); i++)
		count += array[i];
	return (count);
}

void best_sum(vector<int> array, vector<int>& current, vector<int>& result, int goal, int index)
{
	int sum;

	sum = acc(current);
    if (sum == goal) {
		if (result.empty() || result.size() > current.size())
		{
			result.clear();
			for (size_t i = 0; i < current.size(); i++)
				result.push_back(current[i]);
		}
        return;
    }
    if (sum < goal) {
        for (int i = index; i < array.size(); ++i) {
            current.push_back(array[i]);
            best_sum(array, current, result, goal, i);
            current.pop_back();
        }
    }
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
	vector<int> current;

	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		cin >> goal;
		cin >> len;
		array = input_array(len);
		best_sum(array, current, result, goal, 0);
		if (!goal)
		{
			cout << "0\n";
			current.clear();
			result.clear();
			continue ;
		}
		if (!result.empty())
		{
			cout << result.size() << ' ';
			for (int i = result.size() - 1; 0 <= i; i--)
				cout << result[i] << ' ';
		}
		else
			cout << "-1";
		cout << "\n";
		current.clear();
		result.clear();
	}
}
