#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

string remove(string s) {
	stack<char> st;
	string result = "";
	int count[26] = {0};
	bool visited[26] = {false};
	for (size_t i = 0; i < s.size(); i++)
		count[s[i] - 'a']++;
	for (size_t i = 0; i < s.size(); i++)
	{
		int idx = s[i] - 'a';
		count[idx]--;
		if (visited[idx])
			continue;
		while (!st.empty() && st.top() > s[i] && count[st.top() - 'a'] > 0) {
			visited[st.top() - 'a'] = false;
			st.pop();
		}
		st.push(s[i]);
		visited[idx] = true;
	}
	while (!st.empty())
	{
		result = st.top() + result;
		st.pop();
	}
	return result;
}

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		string s;
		cin >> s;

		string result = remove(s);
		cout << result << endl;
	}
	return 0;
}
