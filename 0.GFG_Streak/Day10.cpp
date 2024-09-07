// Longest subarray with sum divisible by K

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longSubarrWthSumDivByK2(int arr[], int n, int k)
{
    // Complete the
    unordered_map<int, int> mp;
    mp[0] = -1;

    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        int rem = sum % k;

        if (rem < 0)
            rem += k;

        if (mp.count(rem))
            ans = max(ans, i - mp[rem]);
        else
            mp[rem] = i;
    }
    return ans;
}

int longSubarrWthSumDivByK(int arr[], int n, int k)
{
    // 1034 / 1120 Time Limit Exceeded
    // Complete the function
    int i{0},
        j{0}, sum{0}, ans{0}, length{0};
    while (i < n)
    {

        sum += arr[j];
        length++;
        if (sum % k == 0)
        {
            ans = max(ans, length);
        }
        j++;
        if (j >= n)
        {
            i++;
            j = i;
            sum = 0;
            length = 0;
        }
    }
    return ans;
}

int main()
{
    // int n = 6, k = 3;
    // int arr[] = {2, 7, 6, 1, 4, 5};
    int n = 5, k = 2;
    int arr[] = {1, 2, -2, 2, 2};

    cout << longSubarrWthSumDivByK2(arr, n, k);

    return 0;
}