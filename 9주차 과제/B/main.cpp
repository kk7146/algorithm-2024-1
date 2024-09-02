#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>& parent, int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

void unionSet(vector<int>& parent, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    if (a < b) {
        parent[b] = a;
    } else {
        parent[a] = b;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> parent(N + 1);
        for (int i = 1; i <= N; ++i) {
            parent[i] = i;
        }
        pair<int, int> lastEdge;
        for (int i = 0; i < N; ++i) {
            int a, b;
            cin >> a >> b;
            if (find(parent, a) == find(parent, b)) {
                lastEdge = {a, b};
            } else {
                unionSet(parent, a, b);
            }
        }
        cout << lastEdge.first << " " << lastEdge.second << endl;
    }
    return 0;
}
