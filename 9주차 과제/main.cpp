#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int find_min_edge(vector<bool>& inMST, vector<int>& key) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < key.size(); v++) {
        if (!inMST[v] && key[v] < min) {
            min = key[v], min_index = v;
        }
    }
    return min_index;
}

int prim(vector<vector<int> >& graph) {
    int V = graph.size();
    vector<int> parent(V); 
    vector<int> key(V, INT_MAX); 
    vector<bool> inMST(V, false); 

    key[0] = 0;
    parent[0] = -1; 

    for (int count = 0; count < V - 1; count++) {
        int u = find_min_edge(inMST, key);

        inMST[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u, key[v] = graph[u][v];
            }
        }
    }

    int result = 0;
    for (int i = 1; i < V; i++)
        result += graph[i][parent[i]];
    return result;
}

int main() {
    int T, N, E;
    cin >> T;

    while (T--) {
        cin >> N >> E;
        vector<vector<int> > graph(N, vector<int>(N, 0));
        for (int i = 0; i < E; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            graph[a][b] = c;
            graph[b][a] = c;
        }

        cout << prim(graph) << "\n";
    }
    return 0;
}
