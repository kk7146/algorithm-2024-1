#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

vector<int>	input_array(size_t len)
{
	vector<int> new_array;
	int			buf;
	int			num[10] = {0, };

	for (size_t i = 0; i < len; i++)
	{
		cin >> buf;
		if (num[buf] < 3)
		{
			new_array.push_back(buf);
			num[buf]++;
		}
	}
	return (new_array);
}

void	print_array(vector<int> array)
{
	for (size_t i = 0; i < array.size(); i++)
		if (array[i] >= 100)
			cout << array[i] << " ";
	cout << "\n";
}

void swap(int *a, int *b ){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void permutation(int r, int depth, vector<int>& array, vector<int>& result){
	if (r == depth)
	{
		int num = array[0] * 100 + array[1] * 10 + array[2];
		if (num > 99 && num % 2 == 0)
			result.push_back(array[0] * 100 + array[1] * 10 + array[2]);
		return;
	}
	for (int i = depth; i < array.size(); i++){
		swap(&array[i], &array[depth]);
		permutation(r, depth + 1, array, result);
		swap(&array[i], &array[depth]);
	}
}

int	main()
{
	size_t		T, len;
	vector<int>	array;
	vector<int>	result;

	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		cin >> len;
		array = input_array(len);
		permutation(3, 0, array, result);
		sort(result.begin(), result.end());
		result.erase(unique(result.begin(),result.end()),result.end());
		print_array(result);
		result.clear();
	}
}
