#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000000
#define MIN 0

using namespace std;

struct chunk {
    bool used = false;
    int minNum = MAX;
    int maxNum = MIN;
};

int maxGap(vector<int> arr, int len) {
    if (len < 2)
		return 0;
	auto [minNum, maxNum] = minmax_element(arr.begin(), arr.end());
    int chunkSize = max(1, (*maxNum - *minNum) / (len - 1));
    int chunkCount = (*maxNum - *minNum) / chunkSize + 1;
    vector<chunk> chunks(chunkCount);

	for (int i = 0; i < len; i++)
	{
		int chunkIndex = (arr[i] - *minNum) / chunkSize;
        chunks[chunkIndex].used = true;
        chunks[chunkIndex].minNum = min(arr[i], chunks[chunkIndex].minNum);
        chunks[chunkIndex].maxNum = max(arr[i], chunks[chunkIndex].maxNum);
	}
    int prevChunkMax = *minNum, maxGap = 0;
	len = chunks.size();
	for (int i = 0; i < len; i++)
	{
		if (!chunks[i].used)
			continue;
		cout << chunks[i].minNum << ' ' << chunks[i].maxNum << endl;
        maxGap = max(maxGap, chunks[i].minNum - prevChunkMax);
        prevChunkMax = chunks[i].maxNum;
	}
	cout << endl;
    return maxGap;
}

vector<int> input_array(int len)
{
    vector<int> new_array(len);
    for (int i = 0; i < len; i++)
        cin >> new_array[i];
    return new_array;
}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int testcase;

	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		int len;
		vector<int> arr;

		cin >> len;
		arr = input_array(len);
		cout << maxGap(arr, len) << '\n';
	}
}