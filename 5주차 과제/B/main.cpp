//정확도 : 이 코드는 문제 설명에 나와 있는 대로 배열 내에 절반 이상을 차지하는 요소가 무조건 있다는 가정 하에 알고리즘은 정확한 결과를 반환합니다.
//시간 복잡도: 평균적인 시간 복잡도는 O(n)이 될 수 있지만, 최악의 경우 시간 복잡도는 O(∞)입니다.
//확률적으로 무한대를 가도 확률이 반 이상인 특정 요소가 나오지 않는 경우가 만약에라도 있을 수 있기 때문입니다.
//공간 복잡도: 추가적인 공간을 거의 사용하지 않습니다 (arr 배열 외에는 몇 개의 기본적인 변수만 사용). 따라서 공간 복잡도는 O(1)입니다.


#include <time.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int half(vector<int> arr)
{
	while (1)
	{
		int random = rand() % arr.size();
		int count = 0;
		for (size_t i = 0; i < arr.size(); i++)
		{
			if (arr[random] == arr[i])
				count++;
			if (count * 2 >= arr.size())
				return (arr[random]);
		}
	}
}

vector<int>	input_array(size_t len)
{
	vector<int> new_array;
	int			buf;
    srand(time(NULL));

	for (size_t i = 0; i < len; i++)
	{
		cin >> buf;
		new_array.push_back(buf);
	}
	return (new_array);
}

int main()
{
	int testcase;

	cin >> testcase;
	srand(time(NULL));
	for (size_t i = 0; i < testcase; i++)
	{
		int len;
		vector<int> arr;

		cin >> len;
		arr = input_array(len);
		cout << half(arr) << '\n';
	}
	
}