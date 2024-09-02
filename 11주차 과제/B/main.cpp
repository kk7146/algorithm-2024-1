#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int memo[21][2001];

int findWays(vector<int> &nums, int target, int idx, int sum)
{
	if (idx == nums.size())
	{
		if (sum == target)
			return 1;
		else
			return 0;
	}
	if (memo[idx][sum + 1000] != -1)
		return memo[idx][sum + 1000];
	int add = findWays(nums, target, idx + 1, sum + nums[idx]);
	int sub = findWays(nums, target, idx + 1, sum - nums[idx]);
	return memo[idx][sum + 1000] = add + sub;
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int target, N;
		cin >> target >> N;

		vector<int> nums(N);
		for (int i = 0; i < N; i++)
		{
			cin >> nums[i];
		}
		memset(memo, -1, sizeof(memo));
		int ways = findWays(nums, target, 0, 0);
		cout << ways << endl;
	}
	return 0;
}
