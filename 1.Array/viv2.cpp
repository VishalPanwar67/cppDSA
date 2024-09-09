#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/palindromic-array-1587115620/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
int revNum(int a)
{
    int x = 0;
    while (a > 0)
    {
        x = x * 10 + a % 10;
        a = a / 10;
    }
    return x;
}

int PalinArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int y = revNum(a[i]);
        if (a[i] != y)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{

    int y = revNum(945);
    cout << y;

    return 0;
}