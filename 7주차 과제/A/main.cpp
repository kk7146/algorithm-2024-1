#include <iostream>
#include <vector>
using namespace std;

bool DFSUtils(int v, const vector<vector<int> >& graph, vector<bool>& visited, vector<bool>& recStack) {
    if(!visited[v]) {
        visited[v] = true;
        recStack[v] = true;
		for (auto i = graph[v].begin(); i != graph[v].end(); i++)
		{
			if (!visited[*i] && DFSUtils(*i, graph, visited, recStack))
                return true;
            else if(recStack[*i])
                return true;
		}
    }
    recStack[v] = false;
    return false;
}

bool DFS(int V, const vector<vector<int> >& graph) {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for(int i = 0; i < V; ++i) {
        if(DFSUtils(i, graph, visited, recStack))
            return true;
    }
    return false;
}

vector<vector<int> > input_graph(int n_n, int v_n)
{
	vector<vector<int> > graph(n_n);

	for (size_t i = 0; i < v_n; i++)
	{
		int a, b;
		cin >> a;
		cin >> b;
		graph[a].push_back(b);
	}
	return (graph);
}

int main() {
    int testcase;

	cin >> testcase;
	for (size_t i = 0; i < testcase; i++)
	{
		int n_n;
		int v_n;
		vector<vector<int> > graph;

		cin >> n_n;
		cin >> v_n;
		graph = input_graph(n_n, v_n);
		if (DFS(graph.size(), graph))
			cout << "true\n";
		else
			cout << "false\n";
	}
    return (1);
}