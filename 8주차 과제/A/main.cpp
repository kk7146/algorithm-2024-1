#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
  
struct Job
{
    int id;
    int deadline;
    int profit;
};
  
bool comparison(Job a, Job b)
{
    if (a.profit == b.profit)
        return a.id < b.id;
    return a.profit > b.profit;
}
  
void printJobScheduling(vector<Job> arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end(), comparison);
    vector<int> result(n);
    vector<bool> slot(n, false);
    for (int i=0; i < n; i++)
        for (int j = arr[i].deadline - 1; j >= 0; j--)
            if (!slot[j])
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
    vector<int> sortedArr;
    for (int i=0; i < n; i++)
        if (slot[i])
            sortedArr.push_back(arr[result[i]].id);
    sort(sortedArr.begin(), sortedArr.end());
    for (int i = 0; i < sortedArr.size(); i++)
        cout << sortedArr[i] << ' ';
    cout << endl;
}
  
int main()
{
    int testcase;
  
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        int len;
        cin >> len;
        vector<Job> arr;
        for (size_t i = 0; i < len; i++)
        {
            Job buf;
            int a, b;
            cin >> a;
            cin >> b;
            buf.id = i + 1;
            buf.deadline = a;
            buf.profit = b;
            arr.push_back(buf);
        }
        printJobScheduling(arr);
    }
}