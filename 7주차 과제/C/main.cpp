#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int BFS(vector<vector<int> > graph, int start, int end)
{
    int n = graph.size();
    vector<int> distance(n, -1), prev(n, -1);
    queue<int> q;
    distance[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        if (current == end) {
            return distance[current];
        }
		for (size_t i = 0; i < graph[current].size(); i++)
		{
			if (distance[graph[current][i]] == -1)
			{
                distance[graph[current][i]] = distance[current] + 1;
				prev[graph[current][i]] = current;
                q.push(graph[current][i]);
            }
		}
    }
    return -1;
	//if (distance[end] == -1) {
    //    return {};
    //}
    //vector<int> path;
    //for (int at = end; at != -1; at = prev[at]) {
    //    path.push_back(at);
    //}
    //reverse(path.begin(), path.end());
//
    //return path;
}

//첫 줄에는 테스트케이스 T(1<=T<=100)가 주어집니다. 
//각 테스트케이스는 두 줄로 주어집니다. 
//첫 줄에는 시작 단어, 끝 단어, 단어 사전에 있는 단어 수 N(1<=N<=5,000)이 주어집니다. 
//둘째 줄에는 N개의 단어가 주어집니다. 
//특정 테스트케이스에 주어지는 단어의 길이는 모두 같으며, 영소문자로만 구성되어 있습니다. 
//단어 사전에는 중복된 단어는 포함되어 있지 않습니다. 단어의 길이는 최소 1, 최대 10입니다.  

bool cmp(string a, string b)
{
	int count = 0;
	int len = a.length();
	for (size_t i = 0; i < len; i++)
		if (a[i] != b[i])
		{
			count++;
			if (count > 1)
				return 0;
		}
	return 1;
}

vector<vector<int> > input_graph(string first, string last, int N, int& flag)
{
	vector<vector<int> > graph(N);
	vector<string>	words;
	string buf;
	words.push_back(first);
	for (size_t i = 0; i < N - 1; i++)
	{
		cin >> buf;
		words.push_back(buf);
		if (buf == last)
			flag = 0;
	}
	for (size_t i = 0; i < N; i++)
		for (size_t j = i + 1; j < N; j++)
			if (cmp(words[i], words[j]))
				graph[i].push_back(j);
	return (graph);
}

int main() {
    int testcase;
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> testcase;
	for (size_t i = 0; i < testcase; i++)
	{
		string first;
		string last;
		int N;
		vector<vector<int> > graph;

		cin >> first;
		cin >> last;
		cin >> N;
		N++;
		int flag = 1;
		if (first == last)
		{
			cout << 0 << endl;
			continue ;
		}
		graph = input_graph(first, last, N, flag);
		if (first.length() == 1)
		{
			cout << 1 << endl;
			continue ;
		}
		if (flag)
		{
			cout << -1 << endl;
			continue ;
		}
		//for (size_t i = 0; i < N; i++)
		//{
		//	for (size_t j = 0; j < graph[i].size(); j++)
		//	{
		//		cout << i << ' '<< graph[i][j] << ' ';
		//	}
		//	cout << endl;
		//}
		cout << BFS(graph, 0, N - 1) << endl;
	}
    return (1);
}