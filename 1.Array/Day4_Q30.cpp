// Chocolate Distribution Problem

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a, long n, long long m)
{
    // code
    sort(a.begin(), a.end());
    long long result = a[n - 1];
    long long diff{0};
    long long i{0}, j{m - 1};
    while (j < n)
    {
        diff = a[j] - a[i];
        cout << "diff " << diff << endl;
        cout << "result " << result << endl;
        result = min(result, diff);
        cout << "result " << result << endl;
        i++;
        j++;
    }
    return result;
}

int main()
{
    // vector<long long> arr = {7, 3, 2, 4, 9, 12, 56};
    vector<long long> arr = {13, 7, 8, 8, 10, 4, 10};
    long long n = arr.size();
    cout << findMinDiff(arr, n, 7);

    return 0;
}