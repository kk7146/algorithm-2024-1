#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void wiggleSort(vector<int>& nums) {
    vector<int> sorted(nums);
    sort(sorted.begin(), sorted.end());
    
    int n = nums.size(), k = (n + 1) / 2, j = n;
    for (int i = 0; i < n; i++) {
        nums[i] = i & 1 ? sorted[--j] : sorted[--k];
    }
}

vector<int> input_array(int len)
{
    vector<int> new_array(len);
    for (int i = 0; i < len; i++)
        cin >> new_array[i];
    return new_array;
}

void print_array(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
	cout << endl;
}

int main()
{
	int testcase;

	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		int len;
		vector<int> arr;

		cin >> len;
		arr = input_array(len);
		wiggleSort(arr);
		cout << len << endl;
		print_array(arr);
	}
}
