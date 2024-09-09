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

long long trappingWater2(int arr[], int n)
{
    
}
long long trappingWater(int arr[], int n)
{
    int a = arr[0], b = arr[n - 1];
    // cout << a << " " << b << endl;
    sort(arr, arr + n);
    Display(arr, n);
    int mx2 = arr[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        // cout << arr[i] << " ";
        if (mx2 > arr[i])
        {
            mx2 = arr[i];
            break;
        }
    }
    cout << endl;
    cout << "mx2 " << mx2 << endl;
    long long water{0};
    cout << a << " " << b << endl;
    for (int i = 0; arr[i] < mx2; i++)
    {
        cout << arr[i] << " V ";
        if (a != arr[i] && b != arr[i])
        {
            water = water + (mx2 - arr[i]);
        }
        cout << " water " << water << endl;
    }
    // cout << " water " << water << endl;
    return water;
}

int main()
{

    // int n = 6;
    // int arr[] = {3, 0, 0, 2, 0, 4};
    // int n = 4;
    // int arr[] = {7,4,0,9};
    // int n = 3;
    // int arr[] = {6, 9, 9};
    // int n = 7;
    // int arr[] = {8, 8, 2, 4, 5, 5, 1};
    int n = 10;
    int arr[] = {1 ,1, 5, 2, 7, 6, 1, 4, 2, 3};
    trappingWater2(arr, n);

    return 0;
}