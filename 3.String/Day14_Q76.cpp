#include <iostream>
#include <string>
using namespace std;

bool solve(string &str, string &pattern, int i, int j)
{
    if (i < 0 && j < 0)
    {
        return true;
    }
    if (i >= 0 && j < 0)
    {
        return false;
    }
    if (i < 0 && j >= 0)
    {
        for (int k = 0; k <= j; k++)
        {
            if (pattern[k] != '*')
            {
                return false;
            }
        }
        return true;
    }
    if (str[i] == pattern[j] || pattern[j] == '?')
    {
        return solve(str, pattern, i - 1, j - 1);
    }
    else if (pattern[j] == '*')
    {
        return (solve(str, pattern, i - 1, j) || solve(str, pattern, i, j - 1));
    }
    else
    {
        return false;
    }
}

bool match(string wild, string pattern)
{
    // code here
    int n = pattern.length();
    int m = wild.length();
    return solve(pattern, wild, n - 1, m - 1);
}

int main()
{

    string wild = "ge*ks";
    string pattern = "geeks";
    cout << match(wild, pattern);
    return 0;
}