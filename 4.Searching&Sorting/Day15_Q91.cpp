// Value equal to index value

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> valueEqualToIndex(int arr[], int n)
{
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (i + 1 == arr[i])
        {
            v.push_back(i + 1);
        }
    }
    return v;
}

void vectorDisplay(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{

    // int n = 5;
    // int arr[] = {15, 2, 45, 12, 7};
    int n = 1;
    int arr[] = {1};
    vector<int> res = valueEqualToIndex(arr, n);
    vectorDisplay(res);
    return 0;
}