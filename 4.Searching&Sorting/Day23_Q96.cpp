#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int lengthBridge(int arr1[], int n, int arr2[], int m)
{
    int s1{0}, s2{0};
    int i{0}, j{0};
    int ans{0};
    while (i < n && j < m)
    {
        // cout << s1 << " " << s2 << " Sum" << endl;
        if (arr1[i] < arr2[j])
        {
            s1 += arr1[i++];
        }
        else if (arr2[j] < arr1[i])
        {
            s2 += arr2[j++];
        }
        else
        {
            ans = ans + max(s1, s2) + arr1[i];
            s1 = s2 = 0;
            i++;
            j++;
        }
        // cout << " ans " << ans << endl;
    }
    while (i < n)
    {
        s1 += arr1[i++];
    }
    while (j < m)
    {
        s2 += arr2[j++];
    }
    ans = ans + max(s1, s2);
    return ans;
}

int main()
{
    int bri1[] = {3, 5, 7, 9, 20, 25, 30, 40, 55, 56, 57, 60, 62};
    int n = sizeof(bri1) / sizeof(bri1[0]);
    // cout << n << endl;
    int bri2[] = {1, 4, 7, 11, 14, 25, 44, 47, 55, 57, 100};
    int m = sizeof(bri2) / sizeof(bri2[0]);
    cout << lengthBridge(bri1, n, bri2, m) << endl;
    return 0;
}