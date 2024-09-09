// Subarray with 0 sum

#include <iostream>
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
bool subArrayExists(int arr[], int n)
{
    if (arr[0] == 0)
    {
        return true;
    }
    int sum;
    for (int i = 0; i < n; i++)
    {
        sum = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            sum = sum + arr[j];
            if (sum == 0)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n = 5;
    // int arr[] = {4,2,-3,1,6};
    int arr[] = {4,2,0,1,6};

    Display(arr, n);
    cout << subArrayExists(arr, n);
    return 0;
}