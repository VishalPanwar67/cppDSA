// Check if a string is repetition of its substring of k-length

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int kSubstrConcat(int n, string s, int k)
{
    if (n % k != 0)
    {
        return 0;
    }

    int i{0};
    set<string> v;
    while (i < n)
    {
        string temp = s.substr(i, k);
        v.insert(temp);
        i += k;
    }

    if (v.size() <= 2)
    {
        return 1;
    }
    return 0;
}

int main()
{
    // string str = "bdac";
    // int k = 2;
    string str = "abcde";
    int k = 2;

    int n = str.length();
    cout << kSubstrConcat(n, str, k);

    return 0;
}

// https://www.geeksforgeeks.org/problems/check-if-a-string-is-repetition-of-its-substring-of-k-length3302/1