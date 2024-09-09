#include <iostream>
#include "BaseArr.cpp"
using namespace std;

void arrArrange(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main()
{
    int arr[] = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
    int size = sizeof(arr) / sizeof(arr[0]);
    // cout << size;
    arrArrange(arr, size);
    Display(arr, size);

    return 0;
}