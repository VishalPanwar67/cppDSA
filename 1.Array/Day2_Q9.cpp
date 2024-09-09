#include <iostream>
#include "BaseArr.cpp"
using namespace std;

int getMinDiff(int arr[], int n, int k)
{
}

int main()
{
    // int n = 5, k = 3;
    // int arr[] = {3, 9, 12, 16, 20};
    // int n = 4, k = 2;
    // int arr[] = {1, 5, 8, 10};
    int n = 4, k = 1;
    int arr[] = {7, 7, 3, 5};
    Display(arr, n);
    cout << getMinDiff(arr, n, k);

    return 0;
}