#include <iostream>
#include <vector>
#include <time.h>

using namespace std;
 
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (vector<int>& array, int start, int end)
{
    int temp = start;
    int random = rand() % (end - start) + start;
    swap(&array[random], &array[start]);
    int pivot = array[start++];
 
    while(start <= end){
        while(array[start] <= pivot && start <= end)
            start++;
        while(array[end] >= pivot && start <= end)
            end--;
        if (start <= end)
            swap(&array[start], &array[end]);
    }
    swap(&array[temp], &array[end]);
    return end;
}
 
void quick_sort(vector<int>& array, int start, int end){
    if (start < end)
    {
        int middle = partition(array, start, end);
        quick_sort(array, start, middle - 1);
        quick_sort(array, middle + 1, end);
    }
}

vector<int>	input_array(size_t len)
{
	vector<int> new_array;
	int			buf;
    srand(time(NULL));

	for (size_t i = 0; i < len; i++)
	{
		cin >> buf;
		new_array.push_back(buf);
	}
	return (new_array);
}

int main()
{
    vector<int>	array;
    int			test_count;
    int			len;
 
    cin >> test_count;
    for (int i = 0; i < test_count; i++)
    {
        cin >> len;
        array = input_array(len);
        quick_sort(array, 0, len - 1);
		for (int i = 0; i < len; i++)
				cout << array[i] << ' ';
    }
    return (1);
}
