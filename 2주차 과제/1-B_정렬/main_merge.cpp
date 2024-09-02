//공간 복잡도는 동적 할당 되는 메모리의 할당에서 결정된다. 
//그렇기에 재귀를 통해서 동적으로 할당이 되는 배열의 깊이에 따라 달라지고
//합병정렬의 재귀는 예시로 8이면 8 4 2 1 이렇게 log n 내려가고 따라서 공간 복잡도는 O(log n)과 비례한다.
#include <iostream>
 
using namespace std;
 
void    merge(int **array, int left, int right, int len, int middle)
{
    int *temp;
    int left_index = left, right_index = middle + 1, temp_index = left;
 
    temp = new int [len];
    while (temp_index <= right)
    {
        if (left_index > middle)
            temp[temp_index++] = (*array)[right_index++];
        else if (right_index > right)
            temp[temp_index++] = (*array)[left_index++];
        else if ((*array)[left_index] <= (*array)[right_index])
            temp[temp_index++] = (*array)[left_index++];
        else
            temp[temp_index++] = (*array)[right_index++];
    }
    for (int i = left; i <= right; i++)
        (*array)[i] = temp[i];
    delete [] temp;
}
 
void    merge_sort(int **array, int left, int right, int len)
{
    int middle = (left + right) / 2;;
 
    if (left < right)
    {
        middle = (left + right) / 2;
        merge_sort(array, left, middle, len);
        merge_sort(array, middle + 1, right, len);
        merge(array, left, right, len, middle);
    }
}
 
//void  check_leak(void)
//{
//  system("leaks a.out");
//}
 
void print_array(int* array, int len)
{
    for (int j = 0; j < len; j++)
    {
        cout << array[j];
        if (j + 1 != len)
            cout << " ";
    }
}
 
int *input_array(int len)
{
    int *array = new int[len];
 
    for (int j = 0; j < len; j++)
        cin >> array[j];
    return (array);
}
 
int main()
{
    int *array;
    int test_count;
    int len;
 
    cin >> test_count;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (int i = 0; i < test_count; i++)
    {
        cin >> len;
        array = input_array(len);
        merge_sort(&array , 0, len - 1, len);
        print_array(array, len);
        if (i + 1 != test_count)
            cout << "\n";
        delete [] array;
    }
    //atexit(check_leak);
    return (1);
}
 