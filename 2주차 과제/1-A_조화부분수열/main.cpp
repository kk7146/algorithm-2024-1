#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <math.h>

using namespace	std;

vector<int>	input_array(int len)
{
	vector<int> array(len);

	for (int i = 0; i < len; i++)
		cin >> array[i];
	return (array);
}
 
int	longest_con_num(vector<int> array, int len)
{
	int			longest = 0;
	vector<int> v_weight(1, 1);
	vector<int> v_num(1, array[0]);
	int			v_index = 0;

	for (int i = 0; i < len - 1; i++)
	{
		if (array[i] == array[i + 1])
			v_weight[v_index]++;
		else
		{
			v_weight.push_back(1);
			v_num.push_back(array[i + 1]);
			v_index++;
		}
	}
	len = v_weight.size();
	for (int i = 0; i < len - 1; i++)
		if (v_num.size() > 1 && abs(v_num[i] - v_num[i + 1]) == 1)
			if (longest < v_weight[i] + v_weight[i + 1])
				longest = v_weight[i] + v_weight[i + 1];
	return (longest);
}

//int	longest_con_num(vector<int> array, int len)
//{
//	int	longest = 0;
//	int	count = 0;
//
//	for (int i = 0; i < len - 1; i++)
//		if (array.size() > 1 && abs(array[i] - array[i + 1]) == 1)
//			if (longest < v_weight[i] + v_weight[i + 1])
//				longest = v_weight[i] + v_weight[i + 1];
//	return (longest);
//}

int	main()
{
	vector<int> array;
	int	test_count;
	int	len;

	cin >> test_count;
	for (int i = 0; i < test_count; i++)
	{
		cin >> len;
		array = input_array(len);
		sort(array.begin(), array.end());
		cout << longest_con_num(array, len) << '\n';
	}
	return (0);
}