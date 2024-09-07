// 301. Remove Invalid Parentheses
// https://leetcode.com/problems/remove-invalid-parentheses/description/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int find_removals(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (st.size() != 0 && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                st.push(')');
            }
        }
    }
    return st.size();
}

void solve(string s, vector<string> &ans, unordered_map<string, bool> &mp, int removals)
{
    if (mp[s])
    {
        return;
    }
    mp[s] = true;

    if (removals == 0)
    {
        int removals_needed = find_removals(s);
        if (removals_needed == 0)
        {
            ans.push_back(s);
        }
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        string leftpart = s.substr(0, i);
        // cout << leftpart << " l" << endl;
        string rightpart = s.substr(i + 1);
        // cout << rightpart << " r" << endl;
        string join = leftpart + rightpart;
        solve(join, ans, mp, removals - 1);
    }
    return;
}

vector<string> removeInvalidParentheses(string s)
{
    unordered_map<string, bool> mp;
    int min_removals = find_removals(s);
    vector<string> ans;
    solve(s, ans, mp, min_removals);
    return ans;
}

void display(vector<string> res)
{
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ", ";
    }
    cout << endl;
}

int main()
{
    string str = "()())()";

    vector<string> res = removeInvalidParentheses(str);

    display(res);

    return 0;
}