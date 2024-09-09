// Factorials of large numbers

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
vector<int> factorial(int N)
{
    vector<int> fact;
    int sum = N;
    for (int i = N - 1; i > 0; i--)
    {
        sum = sum * i;
    }
    while (sum > 0)
    {
        int x = sum % 10;
        sum = sum / 10;
        // cout << sum << " Panwar " << x<< endl;
        fact.insert(fact.begin(), x);
    }
    return fact;
}
vector<int> factorial1(int N)
{
    vector<int> fact;
    vector<int> temp;
}

int main()
{
  
    vector<int> res = factorial(20);
    // vector<int> res = factorial1(5);
    if (res.size() == 0)
    {
        cout << -1;
    }
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }
    return 0;
}