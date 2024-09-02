#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

bool find1(vector<string> map, string str, int R, int C)
{
	int len = str.length();
	for (int i = 0; i < R; i++)
	{
		int size = 0;
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] != '#')
				size++;
			else
				size = 0;
			if (size == len)
			{
				int index = j - len + 1, k = 0;
				for (; k < len; k++)
				{
					if (map[i][index + k] != '.')
						if (map[i][index + k] != str[k])
							break;
				}
				if (k == len)
					return true;
				index = j, k = 0;
				for (; k < len; k++)
				{
					if (map[i][index - k] != '.')
						if (map[i][index - k] != str[k])
							break;
				}
				if (k == len)
					return true;
			}
		}	
	}
	return false;
}

bool find2(vector<string> map, string str, int R, int C)
{
	int len = str.length();
	for (int i = 0; i < C; i++)
	{
		int size = 0;
		for (int j = 0; j < R; j++)
		{
			if (map[j][i] != '#')
				size++;
			else
				size = 0;
			if (size == len)
			{
				int index = j - len + 1, k = 0;
				for (; k < len; k++)
				{
					if (map[index + k][i] != '.')
						if (map[index + k][i] != str[k])
							break;
				}
				if (k == len)
					return true;
				index = j, k = 0;
				for (; k < len; k++)
				{
					if (map[index - k][i] != '.')
						if (map[index - k][i] != str[k])
							break;
				}
				if (k == len)
					return true;
			}
		}	
	}
	return false;
}

int main()
{
	int testcase;

	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		int R, C;
		string str;
		cin >> R;
		cin >> C;
		cin >> str;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		vector<string> map;
			
		for (int i = 0; i < R; i++)
		{
			string str_buf;
			cin >> str_buf;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			map.push_back(str_buf);
		}
		string str_buf(C, '\0');
		map.push_back(str_buf);
		if (find1(map, str, R, C))
		{
			cout << "true\n";
			continue;
		}
		if (find2(map, str, R, C))
		{
			cout << "true\n";
			continue;
		}
		cout << "false\n";
	}
	return 1;
}