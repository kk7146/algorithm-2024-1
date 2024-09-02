#include <iostream>
#include <vector>
using namespace std;
int MOD = 1e9 + 7;
int func(int D, int F, int C) 
{
	vector<vector<int>> dp(D+1, vector<int>(C+1, 0));
	dp[0][0] = 1;
	for(int i=1; i<=D; i++)
		for(int j=1; j<=C; j++)
			for(int k=1; k<=F && k<=j; k++)
				dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % MOD;
	return dp[D][C];
}

int main() {
	int T;
	cin >> T;

	for(int i=0; i<T; i++)
	{
		int D, F, C;
		cin >> D >> F >> C;
		int result = func(D, F, C);
		cout << result << endl;
	}
	return 0;
}
