#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int x, int k)
{
    // Complete the function
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int k = 1, x = 6, n = 5;
    int arr[] = {4, 5, 6, 7, 6};

    cout << search(arr, n, x, k);
    return 0;
}