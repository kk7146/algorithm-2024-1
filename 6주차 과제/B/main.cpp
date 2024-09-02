#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int secondLargest(vector<int> num)
{
    vector<int> loser;
    int max = num[0];

    for (int i = 1; i < num.size(); ++i)
	{
        if (num[i] > max) 
		{
            loser.push_back(max);
            max = num[i];
        }
		else
            loser.push_back(num[i]);
    }
    int secondLargest = *loser.begin();
	for (auto i = loser.begin() + 1; i != loser.end(); i++)
	{
		if ((*i) > secondLargest)
			secondLargest = (*i);
	}
    return secondLargest;
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
		vector<int> arr;

		cin >> len;
		arr = input_array(len);
		cout << secondLargest(arr) << '\n';
	}
}