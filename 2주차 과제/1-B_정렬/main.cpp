#include <iostream>
#include <stdlib.h>

using namespace std;

void	merge_sort(int **array, int left, int right)
{
	int *temp;
	int	middle = (left + right) / 2;;
	int	i = left, j = middle + 1, k = left;

	if (left < right)
	{
		middle = (left + right) / 2;
		merge_sort(array, left, middle);
		merge_sort(array, middle + 1, right);
		temp = (int *)malloc(sizeof(int) * (*array)[0]);
		while (k <= right)
		{
			if (i > middle)
				temp[k++] = (*array)[j++];
			else if (j > right)
				temp[k++] = (*array)[i++];
			else if ((*array)[i] <= (*array)[j])
				temp[k++] = (*array)[i++];
			else
				temp[k++] = (*array)[j++];
		}
		for (int i = left; i <= right; i++) 
			(*array)[i] = temp[i];
		free(temp);
	}
}

void	print_array(int **array, int count)
{
	for (size_t i = 0; i < count; i++)
	{
		for (size_t j = 0; j < array[i][0]; j++)
		{
			cout << array[i][j + 1];
			if (j != array[i][0])
				cout << " ";
		}
		if (i != count)
				cout << "\n";
	}
}

void	input_array(int **array)
{
	int	input;

	cin >> input;
	*array = (int *)malloc(sizeof(int) * input + 1);
	for ((*array)[0] = 0; (*array)[0] < input; ((*array)[0])++)
		cin >> (*array)[(*array)[0] + 1];
}

void	free_array_2(int **array, int num)
{
	for (size_t i = 0; i < num; i++)
		free(array[i]);
	free(array);
}

//void   check_leak(void)
//{
//		system("leaks a.out");
//}

int	main()
{
	int	test_count;
	int **array;

	cin >> test_count;
	array = (int **)malloc(sizeof(int) * test_count);
	for (size_t i = 0; i < test_count; i++)
		input_array(&array[i]);
	for (size_t i = 0; i < test_count; i++)
		merge_sort(&array[i] , 1, array[i][0]);
	print_array(array, test_count);
	//atexit(check_leak);
	free_array_2(array, test_count);
	return (1);
}
