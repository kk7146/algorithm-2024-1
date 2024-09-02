#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

bool isTrue(char c, int d[26], int u[26])
{
	int buf;
	if (c >= 'A' && c <= 'Z')
		buf = c - 'A';
	else if (c >= 'a' && c <= 'z')
		buf = c - 'a';
	if (d[buf] && u[buf])
		return true;
	return false;
}

void func(string str)
{
	int d[26], u[26];
	int bigest = 0;
	int bigest_buf = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			u[str[i]] = 1;
		else if (str[i] >= 'a' && str[i] <= 'z')
			d[str[i]] = 1;
	}
	for (size_t i = 0; i < str.length(); i++)
	{
		if (isTrue(str[i], d, u))
		{
			bigest_buf++;
		}
		i++;
	}
}

int main()
{
	int testcase;

	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		string str;
		cin >> str;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		func(str);
	}
	return 1;
}