/*

#include <iostream>
#include <string>

using namespace std;

int countSubstring(string A, string B) {
	int count = 0;
	size_t pos = A.find(B);

	while (pos != string::npos) {
		count++;
		pos = A.find(B, pos + 1);
	}

	return count;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		string A, B;
		cin >> A >> B;

		cout << countSubstring(A, B) << endl;
	}

	return 0;
}
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int MOD = 1e9 + 7;

int countSubstring(string A, string B) {
	int count = 0;
	vector<int> arr(B.size(), 0);

	for (int i = 1, j = 0; i < B.size(); i++)
	{
		while (j > 0 && B[i] != B[j])
			j = arr[j - 1];
		if (B[i] == B[j])
			arr[i] = ++j;
	}
	for (int i = 0, j = 0; i < A.size(); i++)
	{
		while (j > 0 && A[i] != B[j])
			j = arr[j - 1];
		if (A[i] == B[j]) {
			if (j == B.size() - 1)
			{
				count++;
				j = arr[j];
			}
			else
				j++;
		}
	}
	return count;
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		string A, B;
		cin >> A >> B;
		int result = countSubstring(A, B);
		cout << result % MOD << endl;
	}
	return 0;
}
