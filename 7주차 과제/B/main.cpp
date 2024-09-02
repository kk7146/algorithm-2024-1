#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int minDistance(vector<int> dist, vector<bool> sptSet, int N)
{
    int min = INT_MAX, min_index = -1;

    for (int i = 0; i < N; i++)
        if (sptSet[i] == false && dist[i] <= min)
            min = dist[i], min_index = i;
    return min_index;
}

vector<int> dijkstra(vector<vector<int> > graph, int S, int N)
{
    vector<int> dist(N, INT_MAX);
    vector<bool> sptSet(N, false);

    dist[S] = 0;
    for (int count = 0; count < N - 1; count++)
    {
        int u = minDistance(dist, sptSet, N);
        sptSet[u] = true;
        for (int i = 0; i < N; i++)
            if (!sptSet[i] && graph[u][i] && dist[u] != INT_MAX && dist[u] + graph[u][i] < dist[i])
                dist[i] = dist[u] + graph[u][i];
    }
    return dist;
}

vector<vector<int> > input_graph(int N, int E)
{
	vector<vector<int> > graph(N, vector<int> (N, 0));

	for (size_t i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a;
		cin >> b;
        cin >> c;
        graph[a][b] = c;
	}
	return (graph);
}

int main() {
    int testcase;

	cin >> testcase;
	for (size_t i = 0; i < testcase; i++)
	{
		int N, E, S, K, buf;
        vector<int> K_N;
        vector<int> dist;
		vector<vector<int> > graph;

		cin >> N;
		cin >> E;
        cin >> S;
        cin >> K;
        for (size_t i = 0; i < K; i++)
        {
            cin >> buf;
            K_N.push_back(buf);
        }
		graph = input_graph(N, E);
		dist = dijkstra(graph, S, N);
        for (size_t i = 0; i < K; i++)
        {
            if (dist[K_N[i]] == INT_MAX)
            {
                cout << -1 << ' ';
                continue ;
            }
            cout << dist[K_N[i]] << ' ';
        }
        cout << endl;
	}
    return (1);
}
