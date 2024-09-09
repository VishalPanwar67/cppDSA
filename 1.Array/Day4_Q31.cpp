#include <iostream>
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

int smallestSubWithSum(int arr[], int n, int x)
{
    int minlength = n - 1, temp{0};
    int i{0}, j{0};
    long long sum{0};
    while (i < n)
    {
        temp++;
        sum = sum + arr[j];
        cout << "sum " << sum << endl;
        if (sum > x)
        {
            cout << "  if " << temp << endl;
            i++, j = i;
            sum = 0;
            minlength = min(minlength, temp);
            temp = 0;
        }
        else
        {
            j++;
        }
    }
    cout <<"Vishal "<< minlength;
}

int main()
{
    int x = 51;
    int arr[] = {1, 4, 45, 6, 0, 19};
    // int x = 9;
    // int arr[] = {1, 10, 5, 2, 7};
    // int x = 15;
    // int arr[] = {7,6, 5, 9, 1};
    // int x = 10;
    // int arr[] = {1, 3, 4, 7, 10, 10, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    smallestSubWithSum(arr, n, x);

    return 0;
}