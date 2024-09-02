#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

//unordered_map<char, int> split(string& str, int start, int end)
//{
//    unordered_map<char, int> map;
//    
//    for (int i = start; i < end; ++i)
//        map[str[i]]++;
//    return map;
//}
//
//unordered_map<char, int> merge(string& str, int start, int end)
//{
//    int mid;
//    unordered_map<char, int> left_map;
//    unordered_map<char, int> right_map;
//    
//    if (end - start < 1)
//        return unordered_map<char, int>();
//    mid = end / 2;
//    left_map = split(str, start, mid);
//    right_map = split(str, mid, end);
//    for (unordered_map<char,int>::iterator i = right_map.begin(); i != right_map.end(); i++)
//        left_map[(*i).first] += (*i).second;
//    return left_map;
//}

int bigger(int a, int b)
{
    return (a > b) ? a : b;
}

int divide(string str, int start, int end)
{
    if (end == start)
    {
        if (str[start] == 'Y')
            return (1);
        return (0);
    }
    int mid = (start + end) / 2;
    int left = divide(str, start, mid);
    int right = divide(str, mid + 1, end);

    int count = 0;
    for (int i = mid - 1; i >= start; --i)
    {
    	if (str[i] == 'Y')
            count++;
    	else
        	break;
    }
    for (int i = mid; i <= end; ++i)
    {
        if (str[i] == 'Y')
            count++;
    	else
        	break;
    }
    return bigger(bigger(left, right), count);
}

int find_substring(string str, unordered_map<char,int> map) {
    int maxLength = 0;
    int currentLength = 0;

    for (int i = 0; i < str.length(); i++) 
    {
        if (map.find(str[i]) != map.end()) {
            currentLength++;
        } else {
            maxLength = max(maxLength, currentLength);
            currentLength = 0;
        }
    }
    maxLength = max(maxLength, currentLength);

    return maxLength;
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
        int                     k;
		int						len;

        cin >> str;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> k;
		//if (k == 1)
		//{
		//	cout << str.size() << '\n';
		//	continue;
		//}
        //map = merge(str, 0, str.length());
        len = str.size();
        //for (int i = 0; i < len; i++)
        //    map[str[i]]++;
		//
        //for (unordered_map<char,int>::iterator iter = map.begin(); iter != map.end(); iter++)
        //    if (k <= iter->second)
        //        replace(str.begin(), str.end(), iter->first, 'Y');
        //cout << divide(str, 0, str.length() - 1) << '\n';
        for (int i = 0; i < len; i++)
            map[str[i]]++;
        for (unordered_map<char,int>::iterator iter = map.begin(); iter != map.end(); iter++)
        {
            if (k <= iter->second)
            {
                array[iter->first] = iter->second;
            }
        }
        cout << find_substring(str, array) << '\n';
        map.clear();
        array.clear();
        str.clear();
	}
    return (1);
}
