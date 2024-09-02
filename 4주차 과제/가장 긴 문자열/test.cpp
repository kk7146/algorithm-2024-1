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
    if (end - start == 1)
    {
        if (str[start] == 'Y')
            return (1);
        return (0);
    }
    int mid = start + (end - start) / 2;
    int left = divide(str, start, mid);
    int right = divide(str, mid, end);

    int count = 0;
	//if (left < (end - start) / 2 && right < (end - start) / 2)
	//{
	//}
    for (int i = mid - 1; i >= start; --i)
    {
    	if (str[i] == 'Y')
        	count++;
    	else
        	break;
    }
    for (int i = mid; i < end - 1; ++i)
    {
    	if (str[i] == 'Y')
        	count++;
    	else
        	break;
    }
    return bigger(bigger(left, right), count);
}
 
int    merge_sort(string array, int left, int right, int len)
{
    int middle = (left + right) / 2;;
 
    if (right == left)
    {
        if (array[left] == 'Y')
            return (1);
        return (0);
    }
    if (left < right)
    {
        middle = (left + right) / 2;
        int left_count = merge_sort(array, left, middle, len);
        int right_count = merge_sort(array, middle + 1, right, len);
        int count = 0;
        for (int i = middle - 1; i >= right; --i)
        {
        	if (array[i] == 'Y')
            	count++;
        	else
            	break;
        }
        for (int i = middle; i < left; ++i)
        {
        	if (array[i] == 'Y')
            	count++;
        	else
            	break;
        }
        return bigger(bigger(left_count, right_count), count);
    }
}

int main()
{
	int test_count;

	cin >> test_count;
	for (int i = 0; i < test_count; i++)
	{
        unordered_map<char,int> map;
        string                  str;
        int                     k;
		int						len;

        cin >> str;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> k;
		if (k == 1)
		{
			cout << str.size() << '\n';
			continue;
		}
        //map = merge(str, 0, str.length());
        len = str.size();
        for (int i = 0; i < len; i++)
            map[str[i]]++;
		
        for (unordered_map<char,int>::iterator iter = map.begin(); iter != map.end(); iter++)
            if (k <= iter->second)
                replace(str.begin(), str.end(), iter->first, 'Y');
		for (size_t i = 0; i < len; i++)
			if (str[i] != 'Y')
				str[i] = 'N';
        cout << merge_sort(str, 0, str.length() - 1, len) << '\n';
	}
    return (1);
}