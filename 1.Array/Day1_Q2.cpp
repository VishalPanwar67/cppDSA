#include <iostream>
#include <limits.h>
using namespace std;
void Display(int arr[], int size)
{
    cout << "[ ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "]" << endl;
}

int sumMaxMin(int arr[], int size)
{
    int min{INT_MAX};
    int max{INT_MIN};
    int sum{0};
    for (int i = 0; i < size; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    sum = min + max;
    return sum;
}

int main()
{
    int N = 5;
    int arr[] = {-1 ,- 2, - 3, - 4, - 5};
    Display(arr, N);
    cout<< sumMaxMin(arr, N);
    return 0;
}