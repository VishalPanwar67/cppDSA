// Minimum swaps and K together

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minSwap(int arr[], int n, int k)
{
    // Complet the function
    int count{0};
    for (int i = 0; i < n; i++)
    {
        if (k >= arr[i])
        {
            count++;
        }
    }
    int window = 0;

    for (int i = 0; i < count; i++)
    {
        if (k >= arr[i])
        {
            window++;
        }
    }
    int ans = count - window;

    for (int i = count; i < n; i++)
    {
        if (k >= arr[i])
        {
            window++;
        }
        if (k >= arr[i - count])
        {
            window--;
        }
        ans = min(ans, count - window);
    }
    return ans;
}

int main()
{
    int k = 3;
    int arr[] = {2, 1, 5, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minSwap(arr, n, k);
    return 0;
}