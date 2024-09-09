// Modified Game of Nim

#include <iostream>
// #include <vector>
// #include <bits/stdc++.h>
using namespace std;

void Display(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int findWinner(int n, int A[])
{

    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        flag ^= A[i];
    }

    if (!flag)
    {
        return 1;
    }
    else
    {
        return (n % 2) + 1;
    }
}

int main()
{

    int n = 4;
    int arr[] = {2, 2, 2, 1};

    // int n = 2;
    // int arr[] = {3, 3};
    Display(arr, n);
    cout << findWinner(n, arr);
    return 0;
}