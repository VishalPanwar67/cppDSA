// Winner of an election
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<string> winner(string arr[], int n)
{
    map<string, int> store;
    int max{0};
    string str;
    vector<string> v;

    for (int i = 0; i < n; i++)
    {
        store[arr[i]]++;
    }

    for (auto it : store)
    {
        if (it.second > max)
        {
            max = it.second;
            str = it.first;
        }
    }
    v.push_back(str);
    v.push_back(to_string(max));
    return v;
}

int main()
{

    int n = 13;
    string arr[] = {"john", "johnny", "jackie", "johnny", "john", "jackie",
                    "jamie", "jamie", "john", "johnny", "jamie", "johnny", "john"};

    vector<string> ans = winner(arr, n);

    cout << "The winner is: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}

// https://www.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1