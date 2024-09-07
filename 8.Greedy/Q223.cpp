#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dispaly(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

long long int findMaxProduct(vector<int> &a, int n)
{
    // Write your code here
    //  if(a.size()==2){
    //      if(a[0]==0 || a[1]==0){
    //          return a[0]*a[1];
    //      }
    //  }
    if (a.size() == 1)
    {
        return a[0];
    }

    vector<int> p;
    vector<int> ng;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            p.push_back(a[i]);
        }
        else if (a[i] < 0)
        {
            ng.push_back(a[i]);
        }
    }

    sort(p.begin(), p.end());
    sort(ng.begin(), ng.end());
    dispaly(p);
    dispaly(ng);

    long long int product = 0;
    if (p.size() > 0)
    {
        product = 1;
        for (int i = p.size()-1; i >=0; i--)
        {
            product *= p[i];
            cout << product << " product" << endl;
        }
    }
    cout <<product << " p product" << endl;
    if (ng.size() % 2 == 0 && ng.size() > 1)
    {
        if (product == 0)
        {
            product = 1;
        }
        for (int i = 0; i < ng.size(); i++)
        {
            product *= ng[i];
        }
    }else if (ng.size() > 1)
    {
        if (product == 0)
        {
            product = 1;
        }
        for (int i = 0; i < ng.size() - 1; i++)
        {
            product *= ng[i];
        }
    }
    cout << product << " product" << endl;

    return product;
}

int main()
{
    int n = 69;
    vector<int> a = {7, -2, 7, -1, 2, -3, -10, -2, -9, 6, -5, -10, 9, 4, -5, 6, 0, 2, -10, -5, -6, 1, -6, 6, -3, 7, 7, -9, -10, -4, -9, 4, 9, 10, 3, -7, -6, 6, 3, 7, -3, -2, -10, -2, 10, -3, -9, 0, 7, -1, -3, 5, -5, -4, -3, 2, 3, 2, -7, -8, 9, 10, 10, 2, 4, 2, -8, 2, -3};

    long long int ans = findMaxProduct(a, n);
    cout << ans;
    return 0;
}