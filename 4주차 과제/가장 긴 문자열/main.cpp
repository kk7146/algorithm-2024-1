#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

int bigger(int a, int b)
{
    return (a > b) ? a : b;
}

unordered_map<char, int> split(string& str, int start, int end)
{
    unordered_map<char, int> map;
    
    for (int i = start; i < end; ++i)
        map[str[i]]++;
    return map;
}

unordered_map<char, int> merge(string& str, int start, int end)
{
    int mid;
    unordered_map<char, int> left_map;
    unordered_map<char, int> right_map;
    
    if (end - start <= 1)
        return unordered_map<char, int>();
    mid = end / 2;
    left_map = split(str, start, mid);
    right_map = split(str, mid, end);
    for (unordered_map<char,int>::iterator i = right_map.begin(); i != right_map.end(); i++)
        left_map[(*i).first] += (*i).second;
    return left_map;
}

int divide(string str, unordered_map<char,int> map, int start, int end)
{
    if (end - start <= 1)
    {
        if (map.find(start) != map.end())
            return (1);
        return (0);
    }
    int mid = start + (end - start) / 2;
    int left = divide(str, map, start, mid);
    int right = divide(str, map, mid, end);

    int left_count = 0;
    for (int i = mid - 1; i >= start; --i)
    {
        if (map.find(str[i]) != map.end())
            left_count++;
        else
            break;
    }
    int right_count = 0;
    for (int i = mid; i < end; ++i)
    {
        if (map.find(str[i]) != map.end())
            right_count++;
        else
            break;
    }
    return bigger(bigger(left, right), left_count + right_count);
}

int main()
{
	int test_count;

	cin >> test_count;
	for (int i = 0; i < test_count; i++)
	{
        unordered_map<char,int> map;
        unordered_map<char,int> array;
        string                  str;
        int                     len;
        int                     k;

        cin >> str;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> k;
        len = str.size();
        map = merge(str, 0, str.length());
        for (unordered_map<char,int>::iterator iter = map.begin(); iter != map.end(); iter++)
            if (k <= iter->second)
                array[iter->first] = iter->second;
        cout << divide(str, array, 0, str.length()) << '\n';
	}
    return (1);
}