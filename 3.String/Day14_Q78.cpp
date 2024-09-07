#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int transform2(string A, string B)
{
    if (A.length() != B.length())
    {
        return -1;
    }

    // create a map to store the frequency of characters in string A
    unordered_map<char, int> m;
    int n = A.length();
    for (int i = 0; i < n; i++)
    {
        if (m.count(A[i])) // if the character already exists in the map
            m[A[i]]++;     // increment its frequency
        else
            m[A[i]] = 1; // add the character to the map with a frequency of 1
    }

    // subtract the frequency of characters in string B from the map
    for (int i = 0; i < n; i++)
    {
        if (m.count(B[i]))
            m[B[i]]--;
    }

    // check if all the frequencies in the map are 0, indicating equal frequency of characters in both strings
    for (auto it : m)
    {
        if (it.second != 0) // if frequency is not zero
            return -1;      // strings cannot be transformed into each other, return -1
    }

    // calculate the minimum number of operations required to transform string A into string B
    int i = n - 1, j = n - 1;
    int res = 0;
    while (i >= 0 && j >= 0)
    {
        while (i >= 0 && A[i] != B[j])
        {
            res++; // increment the number of operations required
            i--;   // move the pointer i to the left
        }
        i--;
        j--;
    }
    return res; // returning result
}

int transform(string A, string B)
{
    int m = A.length(), n = B.length();
    int i{m - 1}, j{n - 1}, ans{0};
    int k = i;
    if (m != n)
    {
        return -1;
    }
    cout << A << endl;

    while (i >= 0 && j >= 0)
    {
        if (A[i] != B[j])
        {
            char temp = A[i];
            cout << " temp " << temp << endl;
            A.erase(i, 1);
            cout << " A erase  " << A << endl;
            A = temp + A;
            cout << " A insert  " << A << endl;
            cout << " B insert  " << B << endl;
            ans++;
            k--;
        }
        else
        {
            i--;
            j--;
        }

        if (k < 0)
        {
            cout << -1;
            return -1;
            break;
        }
        cout << "i " << i << " J " << j << endl;
    }
    cout << "i " << i << " J " << j << endl;

    if (i == j)
    {
        cout << "Ans " << ans;
        return ans;
    }
}

int main()
{
    // string A = "abd";
    // string B = "bad";
    // string B = "xyz";
    string A = "GeeksForGeeks";
    string B = "ForGeeksGeeks";

    cout << transform2(A, B);

    return 0;
}