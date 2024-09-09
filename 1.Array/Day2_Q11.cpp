#include <iostream>
#include "BaseArr.cpp"
using namespace std;

int rep(int arr[], int n)
{
    int i{0}, j{n - 1}, rep;
    while (i < n)
    {
        if (arr[i] == arr[j] && i != j)
        {
            return arr[i];
        }
        else if (arr[i] != arr[j] && i != j)
        {
            j--;
        }
        else
        {
            i++;
            j = n - 1;
        }
    }
}

int main()
{
    int n;
    // int arr[] = {1, 3, 4, 2, 2};
    int arr[] = {3,1,3,4,2};
    n = sizeof(arr) / sizeof(arr[0]);
    Display(arr, n);
    cout << rep(arr, n);
    return 0;
}