// Count pairs with given sum

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getPairsCount(int arr[], int n, int k)
{
    int ksum{0};
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                ksum++;
            }
        }
    }
    return ksum;
}
int getPairsCount1(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int val = k - arr[i];
        if (m[val])
        {
            ans = ans + m[val];
        }
        m[arr[i]]++;
    }
    return ans;
}

int main()
{
    int arr[] = {1, 5, 7, 1};
    // int k{6};
    // int arr[] = {1, 1, 1, 1};
    int k{2};
    int size = sizeof(arr) / sizeof(arr[0]);
    // cout << getPairsCount(arr, size, k);
    cout << getPairsCount1(arr, size, k);

    return 0;
}