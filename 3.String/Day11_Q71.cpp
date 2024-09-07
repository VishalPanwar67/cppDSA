// 14. Longest Common Prefix

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

void DisplayVector(vector<string> v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << endl;
    }
    cout << endl;
}

string longestCommonPrefix(vector<string> &strs)
{
    string ans = "";
    sort(strs.begin(), strs.end());
    int n = strs.size();
    int l = strs[0].length(), m = strs[n - 1].length();
    for (int i = 0, j = 0; i < l && j < m; i++, j++)
    {
        if (strs[0][i] == strs[n - 1][j])
        {
            ans += strs[0][i];
        }
        else
        {
            break;
        }
    }
    return ans;
}

int main()
{
    vector<string> str = {"flower",
                          "flow",
                          "flight"};

    sort(str.begin(), str.end());
    DisplayVector(str);
    cout << longestCommonPrefix(str);

    return 0;
}