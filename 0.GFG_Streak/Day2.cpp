// Largest Sum Subarray of Size at least K

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k)
{
    long long int sum{0}, last{0}, ans{INT_MIN};
    int i{0}, j{0};

    while (j < n)
    {
        sum += a[j];
        if ((j - i + 1) < k)
        {
            j++;
        }
        else if ((j - i + 1) == k)
        {
            ans = max(ans, sum);
            j++
        }
        else
        {
            ans = max(ans, sum);
            last += a[i];
            i++;
            if (last < 0)
            {
                sum -= last;
                ans = max(ans, sum);
                last = 0;
            }
            j++;
        }
    }
    return ans;
}

int main()
{
    // long long int n = 4, k = 2;
    // long long int arr[] = {-4, -2, 1, -3};
    long long int n = 6, k = 2;
    long long int arr[] = {1, 1, 1, 1, 1, 1};
    maxSumWithK(arr, n, k);
    return 0;
}

// https://www.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k3121/1