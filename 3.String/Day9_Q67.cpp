// Count the Reversals
#include <iostream>
#include <string>
using namespace std;

int countRev2(string s)
{
    // your code here
    int n = s.length();
    if (n % 2 != 0)
    {
        return -1;
    }

    int open{0}, close{0}, res{0};
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '{')
        {
            open++;
        }
        else
        {
            if (open == 0)
            {
                res++;
                open++;
            }
            else
            {
                open--;
            }
        }
    }
    res += (open + close) / 2;
    return res;
}

int main()
{
    string arr = "}{{}}{{{";
    // lps(arr);
    cout << countRev2(arr);

    return 0;
}