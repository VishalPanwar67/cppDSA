// Longest consecutive subsequence

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

int findLongestConseqSubseq(int arr[], int N)
{
    // Your code here
    sort(arr, arr + N);
    int conseq{0}, temp{0};

    for (int i = 0; i < N; i++)
    {

        if (arr[i] + 1 == arr[i + 1])
        {

            temp++;
            conseq = max(conseq, temp);
        }
        else
        {
            temp = 0;
        }
    }
    if (arr[0] == 0)
    {
        conseq++;
    }
    return conseq + 1;
}

int main()
{
    // int n = 7;
    // int arr[] = {2, 6, 1, 9, 4, 5, 3};
    // int n = 12;
    // int arr[] = {34, 2, 7, 23, 31, 38, 13, 11, 37, 19, 45, 6};
    int n = 7;
    int arr[] = {0, 1, 1, 1, 1, 1, 2};
    Display(arr, n);
    sort(arr, arr + n);
    Display(arr, n);
    cout << findLongestConseqSubseq(arr, n);
    return 0;
}