#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool findPair(int arr[], int size, int n)
{
    // code
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (abs(arr[i] - arr[j]) == n)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{

    int l = 5, n = 45;
    int arr[] = {90, 70, 20, 80, 50};
    cout << findPair(arr, l, n);

    return 0;
}