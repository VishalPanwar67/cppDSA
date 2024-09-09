// find 3 no equal tu given X

#include <iostream>
// #include <vector>
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

bool find3Numbers2(int A[], int n, int X)
{

    sort(A, A + n);
    int i, j, k;
    for (i = 0; i < n - 2; i++)
    {
        j = i + 1;
        k = n - 1;
        while (j < k)
        {
            if (A[i] + A[j] + A[k] == X)
            {
                return 1;
            }
            else if (A[i] + A[j] + A[k] < X)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return 0;
}

bool find3Numbers(int A[], int n, int X)
{

    // Your code Here
    int i{0}, j{i + 1}, k{i + 2};

    int sum;

    while (i < n)
    {
        sum = A[i] + A[j] + A[k];
        if (sum == X)
        {

            return true;
        }
        else
        {
            k++;
        }

        if (k >= n)
        {
            j++;
            k = j + 1;
        }
        if (j >= n)
        {
            i++;
            j = i + 1;
            k = i + 2;
        }
    }
    return false;
}

int main()
{
    int n = 6, X = 13;
    int arr[] = {1, 4, 45, 6, 10, 8};
    // int arr[] = {4, 2, 0, 1, 6};

    Display(arr, n);
    find3Numbers(2arr, n, X);
    // cout << find3Numbers(arr, n, X);
    return 0;
}