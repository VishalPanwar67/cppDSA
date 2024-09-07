// Smallest window containing 0, 1 and 2
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int smallestSubstring(string S)
{
    int zero{-1}, one{-1}, two{-1}, ans = INT_MAX;
    int mn{-1}, mx{-1};
    int n = S.length();

    for (int i = 0; i < n; i++)
    {
        if (S[i] == '0')
        {
            zero = i;
        }
        else if (S[i] == '1')
        {
            one = i;
        }
        else if (S[i] == '2')
        {
            two = i;
        }
        if (zero != -1 && one != -1 && two != -1)
        {
            mn = min(zero, min(one, two));
            mx = max(zero, max(one, two));
            ans = min(ans, (mx - mn + 1));
            // cout << ans << " V" << endl;
        }
    }
    return ans;
}

int main()
{
    string str = "10212";
    cout << smallestSubstring(str);

    return 0;
}

// https://www.geeksforgeeks.org/problems/smallest-window-containing-0-1-and-2--170637/1