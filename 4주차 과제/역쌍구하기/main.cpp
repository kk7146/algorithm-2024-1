#include <iostream>
#include <vector>
 
using namespace std;
 
void    merge(vector<int>& array, int left, int right, int len, int middle, int& count)
{
    int *temp;
    int left_index = left, right_index = middle + 1, temp_index = left;
 
    temp = new int [len];
    while (temp_index <= right)
    {
        if (left_index > middle)
			temp[temp_index++] = array[right_index++];
        else if (right_index > right)
            temp[temp_index++] = array[left_index++];
        else if (array[left_index] <= array[right_index])
            temp[temp_index++] = array[left_index++];
        else
		{
			count += middle - left_index + 1;
			temp[temp_index++] = array[right_index++];
		}
    }
    for (int i = left; i <= right; i++)
        array[i] = temp[i];
    delete [] temp;
}
 
void    merge_sort(vector<int>& array, int left, int right, int len, int& count)
{
    int middle = (left + right) / 2;;

    if (left < right)
    {
        middle = (left + right) / 2;
        merge_sort(array, left, middle, len, count);
        merge_sort(array, middle + 1, right, len, count);
        merge(array, left, right, len, middle, count);
    }
}
 
vector<int>	input_array(size_t len)
{
	vector<int> new_array;
	int			buf;

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
		int	count = 0;

        cin >> len;
        array = input_array(len);
        merge_sort(array , 0, len - 1, len, count);
		cout << count << '\n';
    }
    return (1);
}