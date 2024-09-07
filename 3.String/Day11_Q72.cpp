// Min Number of Flips
#include <iostream>
#include <string>
using namespace std;

int minFlips(string S)
{
    int ans{0}, n = S.length();
    int c1{0}, c2{0};
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0 && S[i] == '0')
        {
            c1++;
        }
        else if (i % 2 == 1 && S[i] == '1')
        {
            c1++;
        }
        if (i % 2 == 0 && S[i] == '1')
        {
            c2++;
        }
        else if (i % 2 == 1 && S[i] == '0')
        {
            c2++;
        }
    }
    if (c1 < c2)
    {
        ans = c1;
    }
    else
    {
        ans = c2;
    }
    return ans;
}
int main()
{
    // string str = "001";
    string str = "0001010111";

    cout << minFlips(str);
    return 0;
}