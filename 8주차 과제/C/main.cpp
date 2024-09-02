#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cal(vector<int> arr, int M)
{
    int n = arr.size();
	int count = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
	{
		if (M >= arr[i])
		{
			M -= arr[i];
            count += 1;
		}
        else
            return (count);
	}
	return (count);
}

int main()
{
	int testcase;

	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		int M, N;
		cin >> M;
		cin >> N;
		vector<int> arr;
		for (size_t i = 0; i < N; i++)
		{
			int buf;
			cin >> buf;
			arr.push_back(buf);
		}
		cout << cal(arr, M) << endl;
	}
}
