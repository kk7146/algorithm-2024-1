#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void minmax(vector<int> arr, int& min, int&max)
{
	min = arr[0];
	max = arr[0];

    for(int i = 1; i < arr.size(); ++i)
	{
        if(arr[i] < arr[i-1])
		{
            if(arr[i] < min)
				min = arr[i];
            if(arr[i-1] > max)
				max = arr[i-1];
        }
		else
		{
            if(arr[i-1] < min)
				min = arr[i-1];
            if(arr[i] > max)
				max = arr[i];
        }
    }
}

vector<int> input_array(int len)
{
    vector<int> new_array(len);
    for (int i = 0; i < len; i++)
        cin >> new_array[i];
    return new_array;
}

int main()
{
	int testcase;

	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		int len;
		int min;
		int max;
		vector<int> arr;

		cin >> len;
		arr = input_array(len);
		minmax(arr, min, max);
		cout << max << ' ' << min << '\n';
	}
}