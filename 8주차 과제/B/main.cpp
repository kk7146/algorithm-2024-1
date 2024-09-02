#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comparison(string a, string b) {
    return a + b > b + a;
}

string return_Nums(bool& flag)
{
	string nums;
	cin >> nums;
	if (nums[0] != '0' || nums[1] != '\0')
		flag = false;
	return nums;
}

void print_num(vector<string> arr)
{
    int n = arr.size();
	int count = 0;
    sort(arr.begin(), arr.end(), comparison);
	for (size_t i = 0; i < arr.size(); i++)
		for (size_t j = 0; j < arr[i].size(); j++)
			cout << arr[i][j];
}

int main()
{
	int testcase;

	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		int N;
		bool flag = true;
		cin >> N;
		vector<string> arr;
		for (size_t i = 0; i < N; i++)
			arr.push_back(return_Nums(flag));
		if (flag)
		{
			cout << '0' << endl;
			continue;
		}
		print_num(arr);
		cout << endl;
	}
}
