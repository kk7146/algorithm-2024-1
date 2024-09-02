#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int W, int N, vector<int>& values, vector<int>& weights) {
    vector<vector<int> > table(N + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= N; i++)
        for (int w = 1; w <= W; w++)
        {
            if (weights[i - 1] <= w)
                table[i][w] = max(table[i - 1][w], table[i - 1][w - weights[i - 1]] + values[i - 1]);
            else
                table[i][w] = table[i - 1][w];
        }
    return table[N][W];
}

vector<int>	input_array(size_t len)
{
	vector<int> new_array(len);

	for (size_t i = 0; i < len; i++)
		cin >> new_array[i];
	return (new_array);
}

int	main()
{
	size_t		T;
	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		int	W, N;
		cin >> W;
        cin >> N;
        vector<int> values(N), weights(N);

        for (int i = 0; i < N; i++)
            cin >> values[i] >> weights[i];
        cout << knapsack(W, N, values, weights) << '\n';
	}
    return (1);
}
