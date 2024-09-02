#include <iostream>
#include <string>
#include <vector>

using namespace std;

int needleman_wunsch(string X, string Y, int G, int M) {
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) 
        dp[i][0] = i * G;
    for (int j = 1; j <= n; j++) 
        dp[0][j] = j * G;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j - 1] + M, min(dp[i - 1][j] + G, dp[i][j - 1] + G));
            }
        }
    return dp[m][n];
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int G, M;
        string X, Y;
        cin >> G >> M >> X >> Y;
        cout << needleman_wunsch(X, Y, G, M) << endl;
    }
    return 0;
}
