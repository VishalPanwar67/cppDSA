#include <iostream>
#include <string>
#include <vector>

using namespace std;

int editDistance(string s, string t)
{
    int n = s.length();
    int m = t.length();
    int oprtn = 0;
    vector<char> store;
    for (int i = 0; i < n; i++)
    {
        store[i] = s[i];
    }

    //  cout << store.size() << " store" << endl;
    
    return oprtn;
}

int main()
{
    string s1 = "geek";
    string s2 = "gesek";
    cout << editDistance(s1, s2);
    return 0;
}