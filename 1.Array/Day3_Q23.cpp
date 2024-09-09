// Maximum Product Subarray

#include <iostream>
// #include <climits>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void Display(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
long long maxProduct(vector<int> arr, int n)
{
    if (arr.size() == 1)
    {
        return arr[0];
    }
    long long product = arr[0];
    long long product2 = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            arr[i] = -arr[i];
        }
        if (arr[i] == 0)
        {
            if (product2 < product)
            {
                product2 = product;
            }
            product = 1;
        }
        else
        {
            product = product * arr[i];
        }
    }

    if (product < product2)
    {
        product = product2;
    }

    cout << product;
}
long long maxProduct2(vector<int> arr, int n)
{
    long long mx = 1, mn = 1;
    long long ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            swap(mx, mn);
        }

        long long num = (long long)arr[i];

        mx = max(num, mx * num);
        mn = min(num, mn * num);

        ans = max(ans, mx);
    }

    return ans;
}

int main()
{

    // vector<int> res = {6, -3, -10, 0, 2};
    // vector<int> res = {2, 3, 4, 5, -1, 0};
    vector<int> res = {8, -2, -2, 0, 8, 0, -6, -8, -6, -1};
    // vector<int> res = {0, 0, -5, 0, 0};
    int n = res.size();
    // maxProduct(res, n);
    cout << maxProduct2(res, n);

    return 0;
}