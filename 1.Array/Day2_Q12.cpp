#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void Display(long long a[], int s)
{
    for (int i = 0; i < s; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void sortArray(long long arr[], int m)
{
    for (int i = 1; i < m; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            int temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
        }
    }
}

void merge(long long arr1[], long long arr2[], int n, int m)
{
    int i = n - 1;
    int j = 0;
    while (i >= 0 && j < m)
    {
        if (arr1[i] >= arr2[j])
        {
            swap(arr1[i], arr2[j]);
            i--;
            j++;
        }
        else
        {
            break;
        }
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

int main()
{
    // int n{3}, m{3};
    // long long arr1[] = {2, 4, 5};
    // long long arr2[] = {3, 6, 7};
    int n{4}, m{5};
    long long arr1[] = {1, 3, 5, 7};
    long long arr2[] = {0, 2, 6, 8, 9};
    Display(arr1, n);
    Display(arr2, m);
    merge(arr1, arr2, n, m);
    Display(arr1, n);
    Display(arr2, m);

    return 0;
}