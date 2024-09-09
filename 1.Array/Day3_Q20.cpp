// Alternate positive and negative numbers

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

void rearrange(int arr[], int n)
{
    vector<int> pos;
    vector<int> neg;
    int i{0}, j{0}, k{0};
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            pos.push_back(arr[i]);
        }
        else
        {
            neg.push_back(arr[i]);
        }
    }

    while (i < pos.size() && j < neg.size())
    {
        arr[k++] = pos[i++];
        arr[k++] = neg[j++];
    }
    while (i < pos.size())
    {
        arr[k++] = pos[i++];
    }
    while (j < neg.size())
    {
        arr[k++] = neg[j++];
    }
   
}

int main()
{
    // int n = 4;
    // int arr[] = {-5, -2, 5, 2};
    // int n = 5;
    // int arr[] = {-2, 3, 2, -3, 4};
    // int n = 9;
    // int arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2};
    int n = 10;
    int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    rearrange(arr, n);
    Display(arr, n);

    return 0;
}