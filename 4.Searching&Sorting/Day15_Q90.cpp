// First and last occurrences of x
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void vectorDisplay(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> find(int arr[], int n, int x)
{
    // code here
    vector<int> ans;
    int mn = n, mx = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }

    if (mn == n && mx == 0)
    {
        ans.push_back(-1);
        ans.push_back(-1);
    }
    else
    {
        ans.push_back(mn);
        ans.push_back(mx);
    }
    return ans;
}

int main()
{
    int n = 9, x = 5;
    int arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};

    vector<int> res = find(arr, n, x);
    vectorDisplay(res);

    return 0;
}