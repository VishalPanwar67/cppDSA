// Remove all duplicates from a given string
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string removeDuplicates(string str)
{
    // code here
    unordered_map<char, int> store;
    string s;
    for (int i = 0; i < str.length(); i++)
    {
        store[str[i]]++;
        if (store[str[i]] <= 1)
        {
            s.push_back(str[i]);
        }
    }
    return s;
}

int main()
{
    string str = "geeksforgeeks";
    cout << removeDuplicates(str);

    return 0;
}