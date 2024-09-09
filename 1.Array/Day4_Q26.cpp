//find max Profit

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int maxProfit(int price[], int n)
{
    // Write your code here..

    int buy1 = INT_MAX, buy2 = INT_MAX,
        profit1 = 0, profit2 = 0;

    for (int i = 0; i < n; i++)
    {
        buy1 = min(buy1, price[i]);
        profit1 = max(profit1, price[i] - buy1);
        buy2 = min(buy2, price[i] - profit1);
        profit2 = max(profit2, price[i] - buy2);
    }
    cout << profit2;
}

int main()
{
    int n = 6;
    int arr[] = {10, 22, 5, 75, 65, 80};
    maxProfit(arr, n);
    return 0;
}