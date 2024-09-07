#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int majorityElement(int a[], int size)
{
    unordered_map<int, int> store;
    for (int i = 0; i < size; i++)
    {
        store[a[i]]++;
    }
    for (auto it : store)
    {
        if (it.second > (size / 2))
        {
            return it.first;
        }
    }
    return -1;
}

int main()
{
    int n = 5;
    int arr[] = {3, 1, 3, 3, 2};
    cout << majorityElement(arr, n);

    return 0;
}