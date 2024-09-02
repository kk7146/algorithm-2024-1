#include <algorithm>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

bool can_sum(vector<int>& array, int goal) {
    vector<bool> table(goal + 1, false);
    table[0] = true;

    for (int i = 0; i <= goal; ++i) {
        if (table[i]) {
			for (size_t j = 0; j < array.size(); j++)
			{
				if (i + array[j] <= goal) {
                    table[i + array[j]] = true;
                }
			}
        }
    }
    return table[goal];
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
		if (can_sum(array, goal))
			cout << "true\n";
		else
			cout << "false\n";
	}
}
