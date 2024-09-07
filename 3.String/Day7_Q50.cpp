// Check if given strings are rotations of each other or not
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool areRotations2(string s1, string s2)
{
    // Your code here
    if (s1.size() != s2.size())
    {
        return false;
    }
    string concat = s1 + s1;

    int ind = concat.find(s2);
    if (ind == -1)
    {
        return false;
    }
    return true;
}

bool areRotations(string s1, string s2)
{
    int i{0}, j{0}, k{0};
    vector<int> points;
    // cout << "Length " << s1.length() << " " << s2.length() << endl;
    while (i < s1.length())
    {
        cout << "s1[i] == s2[j] " << s1[i] << " ==" << s2[j] << endl;
        if (s1[i] == s2[j])
        {
            points.push_back(i);
        }
        i++;
    }
    // cout << points.size() << " size" << endl;
    // cout << points[0] << " size" << endl;
    if (points.size() != 0)
    {
        i = points[k];
    }
    else
    {
        i--;
    }
    cout << i << " " << j << " i and j value" << endl;
    while (j < s2.length())
    {
        cout << "Loop 2 " << endl;
        // cout << "s1[i] == s2[j] " << s1[i] << " ==" << s2[j] << endl;
        if (s1[i] != s2[j])
        {
            k++;
            if (k >= points.size())
            {
                return false;
            }
            i = points[k];
            j = 0;
        }
        i++, j++;
        if (i > s1.length() - 1)
        {
            i = 0;
        }

        // cout << "I " << i << endl;
        // cout << "s1[i] == s2[j] " << s1[i] << " ==" << s2[j] << endl;
    }
    return true;
}

int main()
{
    string s1 = "geeksforgeeks";
    string s2 = "forgeeksgeeks";
    // string s1 = "p";
    // string s2 = "q";
    // string s1 = "mightandmagic";
    // string s2 = "andmagicmigth";

    cout << areRotations2(s1, s2);

    return 0;
}