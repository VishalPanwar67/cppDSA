//find Occurence

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

int countOccurence(int arr[], int n, int k)
{
    // Your code here
    int count = 0;
    int times = n / k;
    unordered_map<int, int> store;
    for (int i = 0; i < n; i++)
    {
        store[arr[i]]++;
    }
    cout << "Element  Frequency" << endl;
    for (auto i : store)
    {
        cout << i.first << " \t " << i.second << endl;
        if (i.second > times)
        {
            count++;
        }
    }
    cout << "\nCount " << count << endl;
}

int main()
{

    // int n = 8;
    // int k = 4;
    // int arr[] = {3, 1, 2, 2, 1, 2, 3, 3};
    int n = 4;
    int k = 3;
    int arr[] = {2,3,3,2};
    Display(arr, n);
    countOccurence(arr, n, k);

    return 0;
}