// Print Anagrams Together
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> Anagrams(vector<string> &string_list)
{
    // code here
    int n = string_list.size();
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> store;

    for (int i = 0; i < n; i++)
    {
        string s = string_list[i];
        sort(s.begin(), s.end());
        store[s].push_back(string_list[i]);
    }

    for (auto it = store.begin(); it != store.end(); it++)
    {
        ans.push_back(it->second);
    }
    return ans;
}

void Displaystring(vector<vector<string>> matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < matrix[0].size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    vector<string> arr = {"act", "god", "cat", "dog", "tac"};

    vector<vector<string>> pri = Anagrams(arr);

    sort(pri.begin(), pri.end());
    Displaystring(pri);
    return 0;
}