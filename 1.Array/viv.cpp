#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void Display(vector<string> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

static bool comp(string a, string b)
{
    return a + b > b + a;
}
string printLargest(vector<string> &arr)
{
    // code here
    sort(arr.begin(), arr.end(), comp);
    string ans = "";
    for (int i = 0; i < arr.size(); i++)
    {
        ans += arr[i];
    }

    return ans;
}

int main()
{
    vector<string> arr = {"3", "30", "34", "5", "9"};
    string res = printLargest(arr);
    cout << res;

    return 0;
}