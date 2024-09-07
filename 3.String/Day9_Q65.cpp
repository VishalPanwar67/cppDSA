// Longest Prefix Suffix :Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lps2(string s)
{
    // Your code goes here
    int n = s.length();
    vector<int> store(n, 0);
    int i = 0, j = 1;
    while (j < n)
    {
        if (s[i] == s[j])
        {
            store[j] = i + 1;
            i++;
            j++;
        }
        else
        {
            if (i != 0)
            {
                i = store[i - 1];
            }
            else
            {
                j++;
            }
        }
    }
    return store.back();
}

int lps(string s)
{
    int i{0}, j = s.length() - 1;
    string tempstr1 = "", tempstr2 = "";
    int maxlength{0};
    while (i < s.length() - 1 && j > 0)
    {
        tempstr1 += s[i];
        tempstr2 = s[j] + tempstr2;
        if (tempstr1 == tempstr2)
        {
            maxlength = tempstr1.length();
        }
        i++;
        j--;
    }
    // cout << "tempstr1 " << tempstr1 << endl;
    // cout << "tempstr2 " << tempstr2 << endl;
    return maxlength;
}

int main()
{
    string arr = "abab";
    // lps(arr);
    cout << lps2(arr);

    return 0;
}