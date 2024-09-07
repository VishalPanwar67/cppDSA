// Minimum characters to be added at front to make string palindrome
#include <iostream>
#include <string.h>
using namespace std;

int minChar(string str)
{
    // Write your code here
    int n = str.length();
    int f{0}, l{n - 1}, ans{0};

    while (f < l)
    {
        if (str[f] == str[l])
        {
            f++;
            l--;
        }
        else
        {
            ans++;
            f = 0;
            l = n - ans - 1;
        }
        // cout << f << " vishal " << l << " ans " << ans << endl;
    }
    return ans;
}

int main()
{
    string str = "AACECAAAA";
    cout << minChar(str);

    return 0;
}