#include <iostream>
#include <queue>
#include <tuple>
#include <set>

using namespace std;

bool func(int A, int B, int C) {
	set<tuple<int, int>> visited;
	queue<tuple<int, int>> q;

	q.push({0, 0});
	visited.insert({0, 0});

	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		if (visited.insert({A, y}).second)
			q.push({A, y});
		if (visited.insert({x, B}).second)
			q.push({x, B});
		if (visited.insert({0, y}).second)
			q.push({0, y});
		if (visited.insert({x, 0}).second)
			q.push({x, 0});
		int buf = min(x, B - y);
		if (visited.insert({x - buf, y + buf}).second)
			q.push({x - buf, y + buf});
		buf = min(y, A - x);
		if (visited.insert({x + buf, y - buf}).second)
			q.push({x + buf, y - buf});
		if (x == C || y == C || x + y == C)
			return true;
	}
	return false;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		if (func(A, B, C))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}
