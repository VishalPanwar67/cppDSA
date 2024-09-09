//Array elements is palindrom or not

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPalindrom(int num)
{
    int inNum = num;
    int x{0};
    while (num > 0)
    {
        x = x * 10 + num % 10;
        num = num / 10;
    }
    if (x == inNum)
    {
        return true;
    }
    return false;
}
int PalinArray(int a[], int n)
{
    // code here
    for (int i = 0; i < n; i++)
    {
        if (!isPalindrom(a[i]))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n = 5;
    int arr[] = {111, 222, 333, 444, 555};
    cout << PalinArray(arr, n);

    return 0;
}