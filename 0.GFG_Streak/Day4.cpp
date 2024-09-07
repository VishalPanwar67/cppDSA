#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int singleElement(int arr[], int N)
{
    // code here
    unordered_map<int, int> store;
    for (int i = 0; i < N; i++)
    {
        store[arr[i]]++;
    }
    for (auto it : store)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
    return -1;
}

int main()
{
    int N = 4;
    int arr[] = {1, 10, 1, 1};
    cout << singleElement(arr, N);
    return 0;
}