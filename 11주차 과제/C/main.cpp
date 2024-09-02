#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int INF = 1e7;
void solve() {
    int N, E;
    cin >> N >> E;
    vector<vector<int>> dist(N, vector<int>(N, INF));
    for (int i = 0; i < N; ++i) dist[i][i] = 0;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    for (int i = 0; i < N; ++i) {
        if (dist[i][i] < 0) {
            cout << "-1\n";
            return;
        }
    }
    int maxDist = -1, start = -1, end = -1;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (dist[i][j] != INF && dist[i][j] > maxDist) {
                start = i;
                end = j;
                maxDist = dist[i][j];
            }
    cout << start << " " << end << " " << maxDist << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
